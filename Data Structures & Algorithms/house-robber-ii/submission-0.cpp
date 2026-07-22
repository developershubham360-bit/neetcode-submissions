class Solution {
public:
    long long solve(vector<int>& nums, int l, int r) {
        long long prev = 0, maxi = 0;

        for (int i = l; i <= r; i++) {
            long long temp = max(maxi, prev + nums[i]);
            prev = maxi;
            maxi = temp;
        }

        return maxi;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1)  
        );
    }
};