class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], mini = nums[0], ans = nums[0];
        for (int i=1;i<nums.size();i++) {
            int temp = maxi;
            maxi = max({nums[i], nums[i]*maxi, nums[i]*mini});
            mini = min({nums[i], nums[i]*mini, nums[i]*temp});
            ans = max(maxi, ans);
        }
        return ans;
    }
};