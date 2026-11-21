#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>

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
    int lengthOfLongestSubstring(string s) {
        int backPointer = 0;
        int frontPointer = 0;
        int longestLength = 0;

        // Points to a character and most recently found index.
        std::unordered_map<char, int> map;

        while (s.size() - backPointer > longestLength) { // add check that front pointer < s.size()
            char current = s[frontPointer];

            if (!map.contains(current)) {
                map.insert({current, frontPointer});
            }
            else {
                backPointer = std::max(backPointer, map[current] + 1);
                map[current] = frontPointer;
            }

            frontPointer++;
            longestLength = std::max(frontPointer - backPointer, longestLength);
        }

        return longestLength;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    string s = "abcabcbb";
    int r = solution.lengthOfLongestSubstring(s);
    std::cout << r << std::endl;

    s = "bbbb";
    r = solution.lengthOfLongestSubstring(s);
    std::cout << r << std::endl;

    s = "pwwkew";
    r = solution.lengthOfLongestSubstring(s);
    std::cout << r << std::endl;

    return 0;
}