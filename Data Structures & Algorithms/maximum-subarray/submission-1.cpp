class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = INT_MIN;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            curSum = max(nums[i], nums[i]+curSum);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
