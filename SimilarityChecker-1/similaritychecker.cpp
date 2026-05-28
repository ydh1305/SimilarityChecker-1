#include <string>
#include <algorithm>

class SimilarityChecker {
public:
	int checkLength(std::string a, std::string b) {
		int longLen = (int)std::max(a.length(), b.length());
		int shortLen = (int)std::min(a.length(), b.length());

		if (shortLen == 0) return 0;
		if (longLen >= 2 * shortLen) return 0;

		int gap = longLen - shortLen;
		return (shortLen - gap) * 60 / shortLen;
	}
};
