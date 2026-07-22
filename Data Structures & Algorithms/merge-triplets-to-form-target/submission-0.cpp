class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool haveA = false, haveB = false, haveC = false;
        int A = target[0], B = target[1], C = target[2];

        for (const auto& t : triplets) {
            int a = t[0], b = t[1], c = t[2];

            // If any component exceeds target, this triplet cannot contribute.
            if (a > A || b > B || c > C) continue;

            if (a == A && b <= B && c <= C) haveA = true;
            if (b == B && a <= A && c <= C) haveB = true;
            if (c == C && a <= A && b <= B) haveC = true;
        }

        return haveA && haveB && haveC;
    }
};