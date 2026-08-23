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

    void solve(int index, string &digits, string &current) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index]];
        for (char letter: letters) {
            current.push_back(letter);
            solve(index+1, digits, current);
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