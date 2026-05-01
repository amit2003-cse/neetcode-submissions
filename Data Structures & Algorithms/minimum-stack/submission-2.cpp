class MinStack {
public:
    stack<int> s;
    stack<int> smin;

    void push(int val) {
        s.push(val);
        if (smin.empty()) {
            smin.push(val);
        } else {
            smin.push(min(smin.top(), val));
        }
    }

    void pop() {
        s.pop();
        smin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};
