class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            res += strs[i] + ".";
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s == "") return {};

        vector<string> res;
        int i = 0;
        string word = "";
        while(s[i] != '\0'){
            if(s[i] == '.'){
                res.push_back(word);
                word = "";
                i += 1;
            } else {
                word += s[i];
                i += 1;
            }
        }

        return res;
    }
};
