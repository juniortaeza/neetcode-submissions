class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parens = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                if(!st.empty()){
                    char open = st.top(); st.pop();
                    char expc = parens[c];
                    if(expc != open)
                        return false;
                } else {
                    return false;
                }
            }
        }

        if(!st.empty())
            return false;
            
        return true;
    }
};
