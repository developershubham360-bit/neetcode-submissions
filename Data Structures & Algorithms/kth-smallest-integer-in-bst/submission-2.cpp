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
    vector<int> temp;
    void inorder(TreeNode* root, int k, int &ans) {
        if (!root) return;
        inorder(root->left, k, ans);
        temp.push_back(root->val);
        if (temp.size() == k) ans = temp.back();
        inorder(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }
};