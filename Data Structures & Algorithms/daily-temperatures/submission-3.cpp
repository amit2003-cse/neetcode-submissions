class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevIndex = s.top();
                s.pop();
                result[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }

        return result;
    }
};
