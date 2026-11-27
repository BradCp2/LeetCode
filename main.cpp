#include <iostream>
#include <vector>

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
    int maxArea(vector<int>& height)
    {
        int p1 = 0;
        int p2 = height.size() - 1;
        int maxArea = 0;

        while (p1 < height.size() - 1 && p2 >= 0) {
            maxArea = max(maxArea, min(height[p1], height[p2]) * max(p2 - p1, p1 - p2));

            if (height[p1] < height[p2]) {
                p1++;
            }
            else {
                p2--;
            }
        }

        return maxArea;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << solution.maxArea(height);

    return 0;
}