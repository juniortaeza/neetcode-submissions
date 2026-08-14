class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        string res = "";
        for(string s : strs)
            res += s + ".";
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty())
            return {};

        int i = 0;
        string word = "";
        vector<string> res;
        while(s[i] != '\0'){
            if(s[i] != '.'){
                word += s[i];
                i += 1;
            } else {
                res.push_back(word);
                word = "";
                i += 1;
            }
        }

        return res;
    }
};
