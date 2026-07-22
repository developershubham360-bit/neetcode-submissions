class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, int target, vector<int> temp, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index == nums.size() || target<0) return;

        temp.push_back(nums[index]);
        backtrack(nums, target-nums[index], temp, index);
        temp.pop_back();
        backtrack(nums, target, temp, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtrack(nums, target, temp, 0);
        return ans;
    }
};
