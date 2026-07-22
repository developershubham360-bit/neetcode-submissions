class Solution {
public:
    int solve(int ind, vector<int> &nums, int target, int sum) {
        if (ind>=nums.size()) {
            if (sum==target) return 1;
            else return 0;
        }
        return solve(ind+1, nums, target, sum+nums[ind])+solve(ind+1, nums, target, sum-nums[ind]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target, 0);
    }
};
