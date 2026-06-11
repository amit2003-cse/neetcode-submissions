class Solution {
public:
    bool solves(int i, int j, vector<vector<int>>& dp, string& s1, string& s2, string& s3) {
        // Base Case: Agar dono strings ke pointers end tak pahunch gaye
        if (i == s1.length() && j == s2.length()) return true;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        int k = i + j;
        bool res = false;

        // Raasta 1: Kya s1 ka character match hua?
        if (i < s1.length() && s1[i] == s3[k]) {
            res = res || solves(i + 1, j, dp, s1, s2, s3);
        }

        // Raasta 2: Kya s2 ka character match hua?
        // Agar Raasta 1 se true mil gaya, toh Raasta 2 check karne ki zaroorat nahi (Short-circuit)
        if (!res && j < s2.length() && s2[j] == s3[k]) {
            res = res || solves(i, j + 1, dp, s1, s2, s3);
        }

        // Store result in DP table
        return dp[i][j] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        // First Principle: Length check filter
        if (s1.length() + s2.length() != s3.length()) return false;

        int m = s1.length(), n = s2.length();
        // size m+1 aur n+1 rakho taaki boundary error na aaye
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        return solves(0, 0, dp, s1, s2, s3);
    }
};