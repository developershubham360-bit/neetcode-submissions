class Solution {
public:
    vector<vector<int>> ans;
    void ibacktrack(vector<int> &nums, int target, vector<int> temp, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i=index;i<nums.size();i++) {
            if (i>index && nums[i]==nums[i-1]) continue;
            if (nums[i] > target)  break;
            temp.push_back(nums[i]);
            backtrack(nums, target-nums[i], temp, i+1);
            temp.pop_back();
        }
    }
    void backtrack(vector<int> &nums, int target, vector<int> &temp, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i=index;i<nums.size();i++) {
            if (i>index && nums[i]==nums[i-1]) continue;
            if (nums[i] > target) break;
            temp.push_back(nums[i]);
            backtrack(nums, target-nums[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(candidates, target, temp, 0);
        return ans;
    }
};