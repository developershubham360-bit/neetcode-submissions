// class Solution {
// public:
//     int solve(int ind, vector<int> &nums, int target, int sum) {
//         if (ind>=nums.size()) {
//             if (sum==target) return 1;
//             else return 0;
//         }
//         return solve(ind+1, nums, target, sum+nums[ind])+solve(ind+1, nums, target, sum-nums[ind]);

//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(0, nums, target, 0);
//     }
// };

class Solution {
public:
    int solveMem2(vector<int>&nums,int target,int i,map<pair<int,int>,int>&dp){
        if(i == nums.size()) return target == 0;
        if(dp.find({target,i}) != dp.end()) return dp[{target,i}];
        int plus =  solveMem2(nums,target - nums[i],i+1,dp);
        int minus = solveMem2(nums,target+nums[i],i+1,dp);
        return dp[{target,i}] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return solveMem(nums,target,0,dp,sum);

        map<pair<int,int>,int>dp2;
        return solveMem2(nums,target,0,dp2);
    }
};


