class Solution {
public:
    int uniquePaths(int m, int n) {
        // Step 1: Poori m x n grid ko 1 se initialize kar diya
        // Isse Row 0 aur Col 0 (Base Cases) automatically 1 set ho gaye!
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Step 2: Loop 1 se shuru hoga (kyunki 0th row/col handled hain)
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // Step 3: Current cell = Upar wala (i-1) + Left wala (j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // Step 4: Aakhiri manzil par total raaste mil jayenge
        return dp[m-1][n-1];
    }
};