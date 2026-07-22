// class Solution {
//     vector<vector<int>> dp;
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         dp = vector<vector<int>>(m, vector<int>(n, -1));
//         return dfs(0, 0, word1, word2, m, n);
//     }

//     int dfs(int i, int j, string& word1, string& word2, int m, int n) {
//         if (i == m) return n - j;
//         if (j == n) return m - i;
//         if (dp[i][j] != -1) return dp[i][j];
//         if (word1[i] == word2[j]){
//             dp[i][j] = dfs(i + 1, j + 1, word1, word2, m, n);
//         } else {
//             int res = min(dfs(i + 1, j, word1, word2, m, n),
//                         dfs(i, j + 1, word1, word2, m, n));
//             res = min(res, dfs(i + 1, j + 1, word1, word2, m, n));
//             dp[i][j] = res + 1;
//         }
//         return dp[i][j];
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, 0));

        for (int j = 0; j <= word2.length(); j++) {
            dp[word1.length()][j] = word2.length() - j;
        }
        for (int i = 0; i <= word1.length(); i++) {
            dp[i][word2.length()] = word1.length() - i;
        }

        for (int i = word1.length() - 1; i >= 0; i--) {
            for (int j = word2.length() - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j],
                                   min(dp[i][j + 1], dp[i + 1][j + 1]));
                }
            }
        }
        return dp[0][0];
    }
};