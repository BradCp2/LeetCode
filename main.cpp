#include <iostream>
#include <unordered_map>
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            auto it = indices.find(complement);

            if (it != indices.end()) {
                return {it->second, i};
            }

            indices[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    vector<int> nums;
    vector<int> output;
    int target;

    // Case 1
    nums = {2,7,11,15};
    target = 9;
    output = solution.twoSum(nums, target);
    std::cout << "[" << output[0] << "," << output[1] << "]" << std::endl;

    // Case 2
    nums = {3,2,4};
    target = 6;
    output = solution.twoSum(nums, target);
    std::cout << "[" << output[0] << "," << output[1] << "]" << std::endl;

    // Case 3
    nums = {3,3};
    target = 6;
    output = solution.twoSum(nums, target);
    std::cout << "[" << output[0] << "," << output[1] << "]" << std::endl;

    return 0;
}