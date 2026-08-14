class Solution {
public:
    bool isPalindrome(string s) {
        string parse = "";
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i]))
                parse += tolower(s[i]);
        }

        // racecar
        int L = 0, R = parse.size()-1;
        while(L <= R){
            if(parse[L] == parse[R]){
                L += 1;
                R -= 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
