/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    pair<ListNode*, ListNode*> reverseList(ListNode* node, int n) {
        if (n == 1) {
            return {node, node->next};
        }
        auto result = reverseList(node->next, n - 1);
        node->next->next = node;
        node->next = result.second;
        return {result.first, node->next};
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseList(head, right).first;
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head;
    }
};