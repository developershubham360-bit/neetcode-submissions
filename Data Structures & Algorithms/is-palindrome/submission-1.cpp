class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for (auto c: s) {
            if (isalnum(c))
                str += tolower(c);
        }
        int i=0, j=str.size()-1;
        while (i<j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
