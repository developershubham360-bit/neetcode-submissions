class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0), window(128, 0);
        int req = 0;
        for (char c: t) {
            if (need[c]==0) req++;
            need[c]++;
        }
        int formed = 0, bestLen = INT_MAX, bestStart = 0, left=0;
        for (int right=0;right<s.size();right++) {
            char c = s[right];
            window[c]++;
            if (need[c]>0 && window[c]==need[c]) formed++;
            while (formed == req) {
                int currentLen = right-left+1;
                if (currentLen<bestLen) {
                    bestLen = currentLen;
                    bestStart = left;
                }
                char leftchar = s[left];
                window[leftchar]--;
                if (need[leftchar]>0 && window[leftchar]<need[leftchar]) {
                    formed--;
                }
                left++;
            }
        }
        return bestLen==INT_MAX ? "":s.substr(bestStart, bestLen);
    }
};
