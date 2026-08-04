class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> count;
    //     vector<vector<int>> freq(nums.size() + 1);

    //     for (int n : nums) {
    //         count[n] = 1 + count[n];
    //     }
    //     for (const auto& entry : count) {
    //         freq[entry.second].push_back(entry.first);
    //     }

    //     vector<int> res;
    //     for (int i = freq.size() - 1; i > 0; --i) {
    //         for (int n : freq[i]) {
    //             res.push_back(n);
    //             if (res.size() == k) {
    //                 return res;
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int& num : nums)
            freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;
            minHeap.push({count, num});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};