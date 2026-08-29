class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int leftMini = prices[0];
        int ans = 0;
        for (int i=1;i<n;i++) {
            if (prices[i]<leftMini) leftMini = prices[i];
            ans = max(ans, prices[i]-leftMini);
        }
        return ans;
    }
};
