#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#define private public
#include "CircularBuffer.h"

class CircularBufferTests : public ::testing::Test 
{
public:
	CircularBuffer<double>* inc;

	void SetUp() override 
    {
		inc = new CircularBuffer<double>(3);
        inc->add(2.1);
        inc->add(-1);
	}
	void TearDown() override 
    {
		delete inc;
	}
};

TEST_F(CircularBufferTests, MaxSize)
{
    EXPECT_EQ(inc->getAllocatedSize(), 3);
}
TEST_F(CircularBufferTests, RemoveAndSize)
{
    inc->remove();
    inc->remove();
    EXPECT_EQ(inc->getSize(), 0);
}
TEST_F(CircularBufferTests, AddAndSize)
{
    inc->add(3.12);
    inc->add(-2.56);
    EXPECT_EQ(inc->getSize(), 3);
}
TEST_F(CircularBufferTests, AddAndRemove)
{
    inc->add(3.12);
    inc->add(-2.56);
    EXPECT_EQ(inc->remove(), -1);
}
TEST_F(CircularBufferTests, Remove1)
{
    EXPECT_DOUBLE_EQ(inc->remove(), 2.1);
}
TEST_F(CircularBufferTests, Remove2)
{
    inc->remove();
    EXPECT_DOUBLE_EQ(inc->remove(), -1);
}
TEST_F(CircularBufferTests, Remove3)
{
    inc->remove();
    inc->remove();
    EXPECT_THROW(inc->remove(), std::exception);
}
TEST_F(CircularBufferTests, IncrementIndex)
{
    int temp = 2;
    inc->incrementIndex(temp);
    EXPECT_EQ(temp, 0);
}
////////////////////
TEST(StringBufferTest, String)
{
    CircularBuffer<std::string> buf(1);
    buf.add("abc");
    EXPECT_EQ(buf.remove(), "abc");
}
TEST(IntBufferTest, Size)
{
    CircularBuffer<int> buf(1);
    buf.add(123);
    EXPECT_EQ(buf.getAllocatedSize(), buf.getSize());
}

