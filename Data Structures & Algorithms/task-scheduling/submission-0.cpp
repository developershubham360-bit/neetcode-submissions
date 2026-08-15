class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (auto it: tasks) {
            mp[it]++;
        }
        int maxFreq = 0;
        int countMax=0;
        for (auto it: mp) {
            int count = it.second;
            if (count>maxFreq) {
                maxFreq = count;
                countMax=1;
            }
            else if(count == maxFreq) {
                countMax++;
            }
        }
        int ans = (maxFreq-1)*(n+1) + countMax;
        ans = max((int)tasks.size(), ans);
        return ans;
    }
};