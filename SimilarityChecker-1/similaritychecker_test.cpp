#include "gmock/gmock.h"
#include "similaritychecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
protected:
	SimilarityChecker similaritychecker;
};

TEST_F(SimilarityCheckerFixture, SameLengthReturns60)
{
	EXPECT_EQ(60, similaritychecker.checkWordLength("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, TwiceOrMoreLengthDiffReturns0)
{
	EXPECT_EQ(0, similaritychecker.checkWordLength("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, PartialScore_AAABB_and_BAA)
{
	EXPECT_EQ(20, similaritychecker.checkWordLength("AAABB", "BAA"));
}

TEST_F(SimilarityCheckerFixture, PartialScore_AA_and_AAE)
{
	EXPECT_EQ(30, similaritychecker.checkWordLength("AA", "AAE"));
}

TEST_F(SimilarityCheckerFixture, IdenticalStringsReturns60)
{
	EXPECT_EQ(60, similaritychecker.checkWordLength("ABCDE", "ABCDE"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
