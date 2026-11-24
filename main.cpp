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
    int reverse(int x)
    {
        int y = 0;

        while (x != 0)
        {
            int digit = x % 10;
            x = x / 10;

            if (INT_MIN / 10 > y || INT_MAX / 10 < y) return 0;

            y = y * 10 + digit;
        }

        return y;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    int x;

    x = 123;
    cout << solution.reverse(x) << endl;

    x = 1 << 29;
    x = solution.reverse(x);

    cout << x << endl;
    cout << solution.reverse(x) << endl;

    x = 123;
    cout << solution.reverse(x) << endl;

    return 0;
}