/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        stack<TreeNode*> stack;
        TreeNode* cur = root;
        TreeNode* visited = nullptr;
        
        while (!stack.empty() || cur) {
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            if (cur->right && cur->right != visited) {
                cur = cur->right;
                continue;
            }

            stack.pop();
            if (!cur->left && !cur->right && cur->val == target) {
                if (stack.empty()) return nullptr;

                TreeNode* parent = stack.top();
                if (parent->left == cur) {
                    parent->left = nullptr;
                } else if (parent->right == cur) {
                    parent->right = nullptr;
                }
            } else {
                visited = cur;
            }

            cur = nullptr;
        }

        return root;
    }
};