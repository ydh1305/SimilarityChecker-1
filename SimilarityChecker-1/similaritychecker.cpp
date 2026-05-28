#include <string>

using std::string;

class SimilarityChecker {
public:
	int checkWordLength(string word1, string word2) {
		int longLen = getLongLength(word1, word2);
		int shortLen = getShortLength(word1, word2);

		if (isEmptyString(shortLen)) return 0;
		if (isOutOfRange(longLen, shortLen)) return 0;

		return calcPartialScore(shortLen, getLenGap(longLen, shortLen));
	}

private:
	int getLongLength(string word1, string word2) {
		return (int)(word1.length() >= word2.length() ? word1.length() : word2.length());
	}

	int getShortLength(string word1, string word2) {
		return (int)(word1.length() <= word2.length() ? word1.length() : word2.length());
	}

	bool isEmptyString(int shortLen) {
		return shortLen == 0;
	}

	bool isOutOfRange(int longLen, int shortLen) {
		return longLen >= 2 * shortLen;
	}

	int getLenGap(int longLen, int shortLen) {
		return longLen - shortLen;
	}

	int calcPartialScore(int shortLen, int lenGap) {
		return (int)((1.0 - (double)lenGap / shortLen) * 60 + 0.5);
	}
};
