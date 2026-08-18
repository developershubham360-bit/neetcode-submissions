class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        map<int, int> freq;

        for(int card: hand) {
            freq[card]++;
        }

        while (!freq.empty()) {
            int smallest = freq.begin()->first;
            for(int j=0;j<groupSize;j++) {
                int card = smallest + j;
                if (freq.find(card) == freq.end()) return false;
                freq[card]--;
                if (freq[card] == 0) freq.erase(card);
            }
        }
        return true;
    }
};