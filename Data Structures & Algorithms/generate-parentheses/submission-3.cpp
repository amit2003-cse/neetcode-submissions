class Solution {
public:
    void solve(int openCount, int closeCount, int n, string& current, vector<string>& result) {
    // 1. Base Case: String poori ban gayi
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // --- CHOICE 1: Add Opening Bracket '(' ---
    if (openCount < n) {
        current.push_back('('); // DO
        
        // Sawaal A: Yahan openCount aur closeCount ki jagah kya jayega?
        solve( openCount+1 , closeCount, n, current, result); // RECURSE
        
        current.pop_back(); // UNDO
    }

    // --- CHOICE 2: Add Closing Bracket ')' ---
    if (closeCount < openCount) {
        current.push_back(')'); // DO
        
        // Sawaal B: Yahan openCount aur closeCount ki jagah kya jayega?
        solve(openCount, closeCount+1 , n, current, result); // RECURSE
        
        current.pop_back(); // UNDO
    }
}

    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};

        vector<string> result;
        string current;

        solve(0,0,n,current,result);

        return result;
    }
};
