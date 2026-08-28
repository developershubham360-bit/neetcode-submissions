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
    int res;
    void dfs(TreeNode* root, int maxi) {
        if (!root) return;
        if (root->val >= maxi) res++;
        maxi = max(maxi, root->val);
        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }
    int goodNodes(TreeNode* root) {
        res = 0;
        dfs(root, root->val);
        return res;
    }
};
