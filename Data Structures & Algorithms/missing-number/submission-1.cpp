class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = n*(n+1)/2;
        long long sum2 = accumulate(nums.begin(), nums.end(),0);
        return sum - sum2;
    }
};