class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0, j=n-1;
        int ans = INT_MIN;
        int curr = 0;
        while (i<j) {
            curr = (j-i)*min(heights[i], heights[j]);
            ans = max(ans, curr);
            if (heights[i] <= heights[j]){
                i++;
            }
            else j--;
        }
        return ans;
    }
};
