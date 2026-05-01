class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: padding
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        int N = n + 2;
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Step 2: interval DP
        for (int len = 2; len < N; len++) {
            for (int left = 0; left + len < N; left++) {
                int right = left + len;

                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = max(
                        dp[left][right],
                        dp[left][k] + dp[k][right] + arr[left] * arr[k] * arr[right]
                    );
                }
            }
        }

        return dp[0][N - 1];
    }
};