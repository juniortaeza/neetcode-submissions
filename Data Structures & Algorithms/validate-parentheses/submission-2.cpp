class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s){
            // if open parentheses
            if(!parens.count(c)){
                open.push(c);
            }

            // else - close parentheses - check match
            else {
                // if stack is empty, nothing to check
                if(open.empty())
                    return false;
                
                // if closing parentheses doesn't match open
                if(open.top() != parens[c])
                    return false;

                // else match, pop
                open.pop();
            }
        }

        // if stack is not empty, no match
        return open.empty();
    }
};
