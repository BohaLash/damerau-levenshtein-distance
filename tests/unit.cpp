#include <iostream>
#include <gtest/gtest.h>
#include <damerau-levenshtein.h>

using namespace std;

TEST(DamerauLevenshteinTest, EmptyStrings) {
    string a = "";
    string b = "";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 0);
}

TEST(DamerauLevenshteinTest, EqualStrings) {
    string a = "abc";
    string b = "abc";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 0);
}

TEST(DamerauLevenshteinTest, Deletion) {
    string a = "abc";
    string b = "ab";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 1);
}

TEST(DamerauLevenshteinTest, Insertion) {
    string a = "abc";
    string b = "abcd";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 1);
}

TEST(DamerauLevenshteinTest, Substitution) {
    string a = "abc";
    string b = "aec";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 1);
}

TEST(DamerauLevenshteinTest, Transposition) {
    string a = "abc";
    string b = "acb";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 1);
}

TEST(DamerauLevenshteinTest, Combined) {
    string a = "abcde";
    string b = "bdcfg";
    EXPECT_EQ(damerauLevenshteinDistance(a, b), 4);
}
