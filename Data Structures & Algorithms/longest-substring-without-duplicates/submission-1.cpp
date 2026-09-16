class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int maxSub = 0;
        for(int r = 0; r < s.size() ; r++){
            while(charSet.contains(s[r])){
                charSet.erase(s[l]);
                l += 1;
            }
            charSet.insert(s[r]);
            maxSub = max(maxSub, r - l + 1);
        }
        return maxSub;
    }
};
