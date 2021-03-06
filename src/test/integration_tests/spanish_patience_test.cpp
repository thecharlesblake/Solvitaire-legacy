//
// Created by thecharlesblake on 10/4/17.
//

#include <gtest/gtest.h>

#include "../test_helper.h"

typedef test_helper th;

const static std::string path = "resources/spanish_patience/";
const static std::string type = "simple-spanish-patience";

TEST(SpanishPatience, SimpleSolvable) {
    EXPECT_TRUE(th::is_solvable(path + "SimpleSolvable.json", type));
}

TEST(SpanishPatience, ComplexSolvable) {
    EXPECT_TRUE(th::is_solvable(path + "ComplexSolvable.json", type));
}

TEST(SpanishPatience, SimpleUnsolvable) {
    EXPECT_FALSE(th::is_solvable(path + "SimpleUnsolvable.json", type));
}

TEST(SpanishPatience, ComplexUnsolvable) {
    EXPECT_FALSE(th::is_solvable(path + "ComplexUnsolvable.json", type));
}
