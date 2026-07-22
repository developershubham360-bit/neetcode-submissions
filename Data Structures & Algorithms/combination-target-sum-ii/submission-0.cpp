class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &candidates, int target, vector<int> temp, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i=index;i<candidates.size();i++) {
            if (i>index && candidates[i-1] == candidates[i]) continue;
            if (candidates[i]>target || target<0) break;
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, temp, 0);
        return ans;
    }
};
