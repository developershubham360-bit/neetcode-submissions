class Solution {
public:
    vector<int> memo; // -1 = unknown, 0 = false, 1 = true

    bool solve(int i, string &s, vector<string> &wordDict) {
        if (i == s.size()) return true;

        if (memo[i] != -1) return memo[i];

        for (string &word : wordDict) {
            int len = word.size();
            if (i + len <= s.size() && s.substr(i, len) == word) {
                if (solve(i + len, s, wordDict)) {
                    return memo[i] = 1;
                }
            }
        }

        return memo[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo.assign(s.size(), -1);
        return solve(0, s, wordDict);
    }
};