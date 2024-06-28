#include <gtest/gtest.h>
#include <gmock/gmock.h>

// A simple test case using gtest
TEST(ExampleTest, BasicAssertions) {
    EXPECT_EQ(1 + 1, 2);
}

// A mock class using gmock
class MockFoo {
public:
    MOCK_METHOD0(DoSomething, void());
};

TEST(MockTest, MockExample) {
    MockFoo mock;
    EXPECT_CALL(mock, DoSomething());
    mock.DoSomething();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}