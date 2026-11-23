#include <iostream>

using namespace std;

/**
 * @brief Base solution class for LeetCode problems.
 *
 * The Solution class is designed to be directly pasteable into
 * LeetCode's editor. LeetCode provides its own execution entry point,
 * so only the Solution class and required includes should be submitted.
 *
 * @note Local testing handled through main(). This function and local testing
 * code should NOT be submitted into LeetCode editor.
 */
class Solution {
public:
    string longestPalindrome(string s)
    {
        const int n = s.size();

        if (n == 0) return "";

        int maxPointer = 0;
        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            int oddLength = expand(s, i, i, n);

            if (oddLength > maxLength) {
                maxLength = oddLength;
                maxPointer = i - oddLength / 2;
            }

            int evenLength = expand(s, i, i + 1, n);

            if (evenLength > maxLength) {
                maxLength = evenLength;
                maxPointer = i - evenLength / 2 + 1;
            }

        }

        return s.substr(maxPointer, maxLength);
    }

private:
    int expand(const string& s, int i, int j, const int n)
    {
        while (i >=0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    std::string s,r;

    s = "babad";
    r = solution.longestPalindrome(s);

    std::cout << r << std::endl;

    s = "acca";
    r = solution.longestPalindrome(s);

    std::cout << r << std::endl;

    s = "ccc";
    r = solution.longestPalindrome(s);

    std::cout << r << std::endl;

    return 0;
}