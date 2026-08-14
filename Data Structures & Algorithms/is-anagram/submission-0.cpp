class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int letters[256] = { 0 };
        for(int i = 0; i < s.size(); i++)
            letters[s[i]-'a'] += 1;

        for(int i = 0; i < t.size(); i++){
            letters[t[i]-'a'] -= 1;
            if(letters[t[i]-'a'] < 0)
                return false;
        }

        return true;
    }
};
