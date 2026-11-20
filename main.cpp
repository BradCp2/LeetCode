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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto headNode = new ListNode();
        auto *headPointer = headNode;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            headPointer->next = new ListNode(sum);
            headPointer = headPointer->next;
        }

        return headNode->next;
    }
};

int main()
{
    // Local testing entry point
    // Add test cases for debugging here.

    Solution solution;

    ListNode l1a = ListNode(2);
    ListNode l1b = ListNode(4);
    ListNode l1c = ListNode(3);

    l1a.next = &l1b;
    l1b.next = &l1c;

    ListNode l2a = ListNode(5);
    ListNode l2b = ListNode(6);
    ListNode l2c = ListNode(3);

    l2a.next = &l2b;
    l2b.next = &l2c;

    auto n = solution.addTwoNumbers(&l1a, &l2a);

    while (n != nullptr) {
        std::cout << n->val << std::endl;
        n = n->next;
    }

    return 0;
}