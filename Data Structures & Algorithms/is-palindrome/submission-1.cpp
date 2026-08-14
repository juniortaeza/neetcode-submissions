class Solution {
public:

    // helper function to parse a string from non-alnums and caps
    string parse(string str){
        string res = "";
        for(char c : str){
            if(isalnum(c))
                res += tolower(c);
        }
        return res;
    }

    bool isPalindrome(string s) {
        // parse string from caps and non-alnums
        string parsedStr = parse(s);
        
        // create left and right pointers
        int L = 0, R = parsedStr.size()-1;
        while(L <= R){
            if(parsedStr[L] == parsedStr[R]){
                L += 1;
                R -= 1;
            } else {
                return false;
            }
        }

        // string is palindrome
        return true;
    }
};
