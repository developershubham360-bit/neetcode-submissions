class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> visited;
    void backtrack(vector<int> &nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (visited[i]) continue;
            cout<<"i-> "<<i<<"\n";
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> res;
    void backtracktwo(vector<int> &nums, int ind) {
        if (ind == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i=ind;i<nums.size();i++) {
            swap(nums[ind], nums[i]);
            backtracktwo(nums, ind+1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // visited.resize(nums.size(), false);
        // backtrack(nums);
        // return ans;
        backtracktwo(nums, 0);
        return res;
    }
};
