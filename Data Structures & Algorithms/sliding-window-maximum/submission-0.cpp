class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i=0;i<n;i++) {
            pq.push({nums[i], i});
            int leftBoundry = i-k+1;
            while (pq.top().second < leftBoundry) {
                pq.pop();
            }
            if (pq.size()>=k) ans.push_back(pq.top().first);
        }
        return ans;
    }
};
/*
push k elements in pq
start from i=k, remove top element 
1 2 1, top=2 ind=1
*/