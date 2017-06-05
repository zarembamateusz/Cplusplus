//
// Created by mwypych on 01.06.17.
//
#include <string>
#include <gtest/gtest.h>
#include "ArabicRoman.h"
#include "../lib/memleak/MemLeakTest.h"
using namespace roman;

class ArabicToRomanTest : public ::testing::Test, MemLeakTest {
public:
};


TEST_F(ArabicToRomanTest, CanConverArabicToRoman) {
    ArabicToRoman first_ (4);
    EXPECT_EQ("IV",first_.Convert());
    ArabicToRoman sec_ (900);
    EXPECT_EQ("CM",sec_.Convert());
    ArabicToRoman thir_ (1001);
    EXPECT_EQ("MI",first_.Convert());
    ArabicToRoman four_ (1949);
    EXPECT_EQ("MCMIL",first_.Convert());
    ArabicToRoman five_ (2589);
    EXPECT_EQ("MMDLXXXIX",first_.Convert());


}



TEST_F(ArabicToRomanTest, CanConverToSmallNumber) {
    ArabicToRoman first_ (-2);
    EXPECT_EQ("",first_.Convert());


}
TEST_F(ArabicToRomanTest, CanConverToMuchNumber) {
    ArabicToRoman first_ (5000);
    EXPECT_EQ("",first_.Convert());


}