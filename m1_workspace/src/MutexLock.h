#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H

#include <pthread.h>

// Non-copyable class to prevent copying of mutexes 
class noncopyable {
protected:
    noncopyable() {}
    ~noncopyable() {}    

private:
    noncopyable(const noncopyable&)    ; 
    const noncopyable& operator=(const noncopyable&); 
}; 

// here we define the MutexLock class 
class MutexLock : public noncopyable {
public:
    MutexLock() {
        pthread_mutex_init(&mutex_, nullptr);
    }

    ~MutexLock() {
        pthread_mutex_destroy(&mutex_); 
    }

    void lock() {
        pthread_mutex_lock(&mutex_);
    }

    void unlock() {
        pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t* get_pthread_mutex() {
        return &mutex_; 
    }

private:
    pthread_mutex_t mutex_; 
}; 

class MutexLockGuard : public noncopyable {
public:
    explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex) {
        mutex_.lock(); 
    }

    ~MutexLockGuard() {
        mutex_.unlock(); 
    }

private:
        MutexLock& mutex_;     
}; 

#define MutexLockGuard(x) static_assert(fals, "Missing guard object name")

#endif // MUTEXLOCK_H