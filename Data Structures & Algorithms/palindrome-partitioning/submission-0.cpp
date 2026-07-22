class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string& s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int index) {

        // Base case
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible partition
        for(int end = index; end < s.size(); end++) {

            // Check palindrome
            if(isPalindrome(s, index, end)) {

                // Choose
                path.push_back(s.substr(index, end - index + 1));

                // Explore
                backtrack(s, end + 1);

                // Undo
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);

        return ans;
    }
};