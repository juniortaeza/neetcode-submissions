class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> m1, m2;
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i], c2 = t[i];
            m1[c1]++;
            m2[c2]++;
        }

        return m1 == m2;
    }
};
