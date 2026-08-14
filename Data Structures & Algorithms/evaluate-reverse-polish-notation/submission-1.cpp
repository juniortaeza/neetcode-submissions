class Solution {
public:

    enum Operator { ADD, SUB, MUL, DIV };

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            // if operator detected, compute
            if(s=="+" || s=="-" || s=="*" || s=="/") {
                // operate on two elements
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                // determine which operator to use
                enum Operator op;
                if(s=="+") op = ADD;
                if(s=="-") op = SUB;
                if(s=="*") op = MUL;
                if(s=="/") op = DIV;

                // switch statement operation, push result to stack
                switch(op){
                    case 0:
                        st.push(num2+num1);
                        break;
                    case 1:
                        st.push(num2-num1);
                        break;
                    case 2:
                        st.push(num2*num1);
                        break;
                    case 3:
                        st.push(num2/num1);
                        break;
                    default:
                        break;
                }
            }

            // otherwise add num to stack
            else {
                st.push(stoi(s));
            }
        }
        // result will be at the top of the stack
        return st.top();
    }
};
