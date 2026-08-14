class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> m1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            m1[c]++;
        }

        unordered_map<char, int> m2;
        for(int i = 0; i < t.size(); i++){
            char c = t[i];
            m2[c]++;
        }

        for(auto key : m1){
            char c = key.first;
            int n = key.second;
            if(m2.find(c) == m2.end())
                return false;
            if(m2.find(c)->second != n)
                return false;
        }

        return true;
    }
};
