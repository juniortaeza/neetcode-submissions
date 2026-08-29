class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = s.size()-1;
        while(lp <= rp){

            char lc = s[lp];
            char rc = s[rp];

            if(!isalnum(lc)){
                lp++; continue;
            }
            if(!isalnum(rc)){
                rp--; continue;
            }

            if(tolower(lc) != tolower(rc))
                return false;

            lp++;
            rp--;

        }
        
        return true;
    }
};
