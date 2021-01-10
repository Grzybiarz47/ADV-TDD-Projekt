#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CircularBufferTests.h"

/*******
 * Repozytorium:
 * https://github.com/Grzybiarz47/ADV-TDD-Projekt
 * 
********/

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}