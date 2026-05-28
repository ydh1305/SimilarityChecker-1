#include "gmock/gmock.h"
#include "similaritychecker.cpp"

using namespace testing;

TEST(SimilarityChecker, SameLengthReturns60)
{
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.checkLength("ASD", "DSA"));
}

TEST(SimilarityChecker, TwiceOrMoreLengthDiffReturns0)
{
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.checkLength("A", "BB"));
}

TEST(SimilarityChecker, PartialScore_AAABB_and_BAA)
{
	SimilarityChecker checker;
	EXPECT_EQ(20, checker.checkLength("AAABB", "BAA"));
}

TEST(SimilarityChecker, PartialScore_AA_and_AAE)
{
	SimilarityChecker checker;
	EXPECT_EQ(30, checker.checkLength("AA", "AAE"));
}

TEST(SimilarityChecker, IdenticalStringsReturns60)
{
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.checkLength("ABCDE", "ABCDE"));
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
