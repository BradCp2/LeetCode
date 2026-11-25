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
    bool isPalindrome(int x)
    {
        if (x < 0) return false;

        int y = 0;

        for (int t = x; t >0; t = t/10)
        {
            if (INT_MAX / 10 < y) {
                return false;
            }
            y = y*10 + t%10;
        }

        while (x > 0)
        {
            if (x%10 != y%10) return false;
            x = x/10;
            y = y/10;
        }

        return true;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    int x;
    bool r;

    x = 1000000001;
    r = solution.isPalindrome(x);
    std::cout << r << std::endl;

    x = 14536;
    r = solution.isPalindrome(x);
    std::cout << r << std::endl;

    x = -101;
    r = solution.isPalindrome(x);
    std::cout << r << std::endl;

    x = 0;
    r = solution.isPalindrome(x);
    std::cout << r << std::endl;

    x = 1234567899;
    r = solution.isPalindrome(x);
    std::cout << r << std::endl;

    return 0;
}