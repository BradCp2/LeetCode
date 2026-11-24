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
    string convert(string s, int numRows)
    {
        int blockLength = (numRows - 1) * 2;
        long stringLength = s.size();

        string result;

        if (blockLength == 0) return s;

        // Do step n=0 and n=numRows-1 before and after due to 1 item in pattern
        for (int blockIndex = 0; blockIndex < stringLength; blockIndex += blockLength)
        {
            result += s[blockIndex+0];
        }

        for (int step =1; step <= numRows - 2; step++)
        {
            for (int blockIndex = 0; blockIndex-blockLength < stringLength; blockIndex += blockLength)
            {
                if (blockIndex+step >= stringLength) break;
                result += s[blockIndex+step];

                if (blockIndex+(blockLength-step) >= stringLength) break;
                result += s[blockIndex+(blockLength-step)];
            }
        }

        for (int blockIndex = 0; blockIndex < stringLength; blockIndex += blockLength)
        {
            if (blockIndex+(numRows-1) >= stringLength) break;
            result += s[blockIndex+(numRows-1)];
        }


        return result;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    string s,r;
    int numRows;

    s = "PAYPALISHIRING";
    numRows = 3;

    r = solution.convert(s, numRows);

    std::cout << r << std::endl;
    std::cout << "PAHNAPLSIIGYIR" << std::endl;

    numRows = 4;

    r = solution.convert(s, numRows);

    std::cout << r << std::endl;
    std::cout << "PINALSIGYAHRPI" << std::endl;

    return 0;
}