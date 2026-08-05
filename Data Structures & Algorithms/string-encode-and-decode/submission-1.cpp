class Solution {
public:

    string encode1(vector<string>& strs) {
        string res;
        for (const string& s: strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    string encode(vector<string> &strs) {
        string res;
        for (auto it: strs) {
            res += to_string(it.size()) + "#" + it;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while (i<s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }

    vector<string> decode1(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
