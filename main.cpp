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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            // Calculate partition positions.
            int partitionA = (low + high) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            // Get values surrounding the partitions.
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                // Odd
                if ((m+n) % 2 != 0)
                {
                    return max(maxLeftA, maxLeftB);
                }
                // Even
                else
                {
                    return static_cast<double>(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2;
                }
            }
            // move left
            if (maxLeftA > minRightB)
            {
                high = partitionA - 1;
            }
            // move right
            else
            {
                low = partitionA + 1;
                // Move partition A right.
            }
        }

        return -1;
    }
};


int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    vector<int> nums1, nums2;
    double result;

    nums1 = {1,2};
    nums2 = {3,4};

    result = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << result << std::endl;

    nums1 = {};
    nums2 = {10,20};

    result = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << result << std::endl;

    nums1 = {8,9,13};
    nums2 = {10,11};

    result = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << result << std::endl;

    return 0;
}