#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include "MutexLock.h"

// A thread-safe counter 
class Counter {
    // copy-ctor and assignment should be private by default for a class.
    public:
        Counter() : value_(0) {}
        int64_t value() const ; 
        int64_t getAndIncrease(); 

    private:
        int64_t value_; 
        mutable MutexLock mutex_;         
}; 

int64_t Counter::value() const {
    // 
    MutexLockGuard lock(mutex_); 
    return value_; 
}

int64_t Counter::getAndIncrease() {
    MutexLockGuard lock(mutex_);
    int64_t ret = value_++; 
    return ret; 
}


// number of iterations to perform in each thread 
constexpr int kIterations = 10000; 

// this is the unit of the function to be executed by the thread 
void IncrementCounter(Counter& counter, int iterations) {
    for (int i = 0; i < iterations; i++) {
        counter.getAndIncrease(); 
    }
}

TEST(Ch0101CounterTest, IncrementCounter) {
    Counter counter; 
    int num_threads = 4; 
    std::vector<std::thread> threads; 

    // launch threads to increment the counter 
    for (int i = 0; i < num_threads; i++) {
        // when we use std::vector#emplace_back upon the std::thread it means {1. create instance and insert to vector, 2. trigger the thread to exeucte immediately as the thread instance is created.}
        // create the instance of thread to execute the function -- IncrementCounter 
        // by passing two parameters one is the ref(coutner): Counter&, the other is kIterations:int
        threads.emplace_back(IncrementCounter, std::ref(counter), kIterations); 
    }

    // wait for all threads to finish 
    for (auto& thread : threads) {
        thread.join(); 
    }

    // check the final counter value 
    EXPECT_EQ(counter.value(), num_threads * kIterations); 
}

void ReadCounter(const Counter& counter, int64_t* result, int iterations) {
    for (int i = 0; i < iterations; i++) {
        *result = counter.value(); 
    }
}

TEST(Ch0101CounterTest, ReadWhileIncrementTest) {
    Counter counter; 
    int num_threads = 4; 
    int read_iterations = kIterations; 
    std::vector<std::thread> threads; 
    std::vector<int64_t> results(num_threads, 0); 

    // launch threads to read the counter 
    for (int i = 0; i < num_threads; i++) {
        // here we use the std::ref(counter) is to make sure we really passing the pointer of the counter actually the -- address 
        // to the emplace_back function instead of passing a value 

        // and the &results[i] and read_iteraitons are all the parameters passing to the thread instances. 
        threads.emplace_back(ReadCounter, std::ref(counter), &results[i], read_iterations); 
    }

    // launch threads to increment the counter 
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back(IncrementCounter, std::ref(counter), kIterations); 
    }

    // wait for all threads to finish 
    for (auto& thread : threads) {
        thread.join(); 
    }

    // here we check the final counter value 
    EXPECT_EQ(counter.value(), num_threads * kIterations); 

    // here we double check that no read operation returned an unexpected value 
    for (const auto& result : results) {
        EXPECT_LE(result, counter.value()); 
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}