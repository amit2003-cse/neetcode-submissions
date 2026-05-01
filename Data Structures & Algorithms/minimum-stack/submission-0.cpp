class MinStack {
    stack<int> s;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_stack.empty() || val <= min_stack.top())
        min_stack.push(val);
        
    }
    
    void pop() {
        if(min_stack.top() == s.top())
        min_stack.pop();
        s.pop();
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
       return min_stack.top();
    }
};
