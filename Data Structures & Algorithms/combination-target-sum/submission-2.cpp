class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, int target, vector<int>& temp, int index, int sum) {
        // base case
        if (index == nums.size() || sum>target) {
            return;
        }
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        backtrack(nums, target, temp, index, sum+nums[index]);
        temp.pop_back();
        backtrack(nums, target, temp, index+1, sum);




        // for all choices {
            // if (choice invalid) contine
            // make choice
            // solve(index+1)
            //undo choice

        // }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtrack(nums, target, temp, 0, 0);
        return ans;
    }
};
