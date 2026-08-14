class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        while(L < R){
            char cL = s[L];
            char cR = s[R];

            if(!isalnum(cL) && !isalnum(cR)){
                L++; R--;
            } else if(!isalnum(cL) && isalnum(cR)){
                L++;
            } else if(isalnum(cL) && !isalnum(cR)){
                R--;
            } else {
                if(tolower(cL) != tolower(cR))
                    return false;

                L += 1;
                R -= 1;
            }
        }
        return true;
    }
};