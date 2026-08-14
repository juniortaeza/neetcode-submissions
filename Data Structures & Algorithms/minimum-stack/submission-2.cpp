class MinStack {
public:

    stack<int> main;
    stack<int> mins;

    MinStack() { }
    
    void push(int val) {
        main.push(val);
        val = min(val, (mins.empty()) ? val : mins.top());
        mins.push(val);

    }
    
    void pop() {
        main.pop();
        mins.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
