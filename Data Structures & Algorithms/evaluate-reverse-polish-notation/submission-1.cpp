class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int result = 0;

                if (c == "+") result = a + b;
                else if (c == "-") result = a - b;
                else if (c == "*") result = a * b;
                else if (c == "/") result = a / b;

                s.push(result);
            } else {
                int num = stoi(c);
                s.push(num);
            }
        }
        return s.top();
    }
};
