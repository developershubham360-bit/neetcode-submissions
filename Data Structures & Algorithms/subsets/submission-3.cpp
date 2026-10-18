class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, int index, vector<int> temp) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        backtrack(nums, index+1, temp);
        temp.pop_back();
        backtrack(nums, index+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int> temp;
        backtrack(nums, index, temp);
        return ans;
    }
};
