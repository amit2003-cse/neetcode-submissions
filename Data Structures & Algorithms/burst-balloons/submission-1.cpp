class Solution {
public:
    int solve(int i,int j,vector<int>& A, vector<vector<int>>& dp ){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int max_coin = 0;

        for(int k=i;k<=j;k++){
            int curr_coin = solve(i,k-1,A,dp) +
                            solve(k+1,j,A,dp)  +
                            (A[i-1] * A[k] * A[j+1]);
            max_coin = max(max_coin,curr_coin);
        }

        return dp[i][j]= max_coin;

    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        vector<int> A(n+2,1);


        for(int i=1;i<=n;i++){
            A[i]= nums[i-1];
        }

        return solve(1,n,A,dp);

    }
};
