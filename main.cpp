#include <cstdint>
#include <iostream>
#include <string>

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
    int myAtoi(string s)
    {
        int result = 0;
        int sign = 1;

        // Strip leading whitespace
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i == s.size()) return 0;

        // Check sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        // Set limit as -ve can be larger than +ve
        int limit = (sign == -1) ? INT_MIN : -INT_MAX;

        // Read only numbers
        for (; i < s.size(); i++)
        {
            char c = s[i];

            if (c < '0' || c > '9') break;

            int digit = c - '0';

            if (result < limit / 10 ||
                (result == limit / 10 && digit > -(limit % 10)))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 - digit;
        }

        // flip value if +ve
        return sign == 1 ? -result : result;
    }
};




int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    string s;

    s = "-2147483648";
    cout << solution.myAtoi(s) << endl;

    s = "     22d2";
    cout << solution.myAtoi(s) << endl;

    s = "-91283472332";
    cout << solution.myAtoi(s) << endl;

    s = "-+12";
    cout << solution.myAtoi(s) << endl;

    return 0;
}