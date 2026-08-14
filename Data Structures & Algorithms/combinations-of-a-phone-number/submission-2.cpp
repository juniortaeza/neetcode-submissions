class Solution {
private:
    void generateCombinations(const string& digits, const unordered_map<char, string>& digitToChar, int i, string currStr, vector<string>& res){
        // Base Case
        if(currStr.size() == digits.size()){ 
            res.push_back(currStr); 
            return; 
        }

        for(char c : digitToChar.at(digits[i]))
            generateCombinations(digits, digitToChar, i+1, currStr+c, res);
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        unordered_map<char, string> digitToChar = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        generateCombinations(digits, digitToChar, 0, "", res);
        return res;
    }
};
