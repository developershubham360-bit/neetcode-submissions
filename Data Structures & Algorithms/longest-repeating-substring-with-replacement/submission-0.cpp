class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxCount = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right] - 'A']++;

            // Maximum frequency in the window
            maxCount = max(
                maxCount,
                freq[s[right] - 'A']
            );

            // Number of replacements required
            while ((right - left + 1) - maxCount > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum window length
            maxLen = max(
                maxLen,
                right - left + 1
            );
        }

        return maxLen;
    }
};