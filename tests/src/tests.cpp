#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CircularBufferTests.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}