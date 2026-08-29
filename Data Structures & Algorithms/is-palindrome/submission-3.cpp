class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = s.size()-1;
        while(lp <= rp){
            char lc = s[lp];
            char rc = s[rp];
            if(!isalnum(lc) && isalnum(rc)){
                lp++;
            } else if(isalnum(lc) && !isalnum(rc)){
                rp--;
            } else if(!isalnum(lc) && !isalnum(rc)){
                lp++;
                rp--;
            } else {
                if(tolower(lc) != tolower(rc)){
                    return false;
                }
                lp++;
                rp--;
            }
        }
        return true;
    }
};
