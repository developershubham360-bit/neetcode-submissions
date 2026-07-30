class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_map<char, int> mp;
        // for (auto it: s) {
        //     mp[it]++;
        // }
        // for (auto it: t) {
        //     mp[it]--;
        // }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
        
    }
};
