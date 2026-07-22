class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, vector<int> &tmp, int idx) {
        if (idx == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[idx]);
        backtrack(nums, tmp, idx+1);
        tmp.pop_back();
        backtrack(nums, tmp, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums, tmp, 0);
        return ans;
    }
};
