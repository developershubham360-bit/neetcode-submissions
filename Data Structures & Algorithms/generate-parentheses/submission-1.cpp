class Solution {
public:
    vector<string> ans;
    void backtrack(string path, int open, int close, int n) {
        if (path.size() == 2*n) {
            ans.push_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            backtrack(path, open+1, close, n);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            backtrack(path, open, close+1, n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path;
        backtrack(path, 0, 0, n);
        return ans;
    }
};