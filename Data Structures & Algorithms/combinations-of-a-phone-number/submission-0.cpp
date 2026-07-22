class Solution {
public:
    
    vector<string> ans;

    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int index, string &digits, string &current)
    {
        // Base case
        if(index == digits.length())
        {
            ans.push_back(current);
            return;
        }

        // Get characters for current digit
        string letters = mp[digits[index]];

        // Try every character
        for(char ch : letters)
        {
            // Choose
            current.push_back(ch);

            // Explore
            solve(index + 1, digits, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};

        string current = "";

        solve(0, digits, current);

        return ans;
    }
};