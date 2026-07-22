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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // vector<int> temp;
            int s = q.size();
            for (int i=0;i<s;i++) {
                TreeNode* fNode = q.front();
                q.pop();
                if (i==s-1)
                    res.push_back(fNode->val);
                if (fNode->left) q.push(fNode->left);
                if (fNode->right) q.push(fNode->right);
            }
            // res.push_back(temp);
        }
        return res;
    }
};
