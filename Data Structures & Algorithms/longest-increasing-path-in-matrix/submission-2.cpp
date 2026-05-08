class Solution {
public:
    
    int dfs(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& matrix ){
        if(dp[i][j] >0) return dp[i][j];

        int row = matrix.size();
        int col = matrix[0].size();
        

         int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            int max_neighbor = 0;
            for(int a=0;a<4;a++){
                int nr = i+dr[a];
                int nc = j+dc[a];

                if(nr>=0 && nr<row && nc>=0 && nc<col && matrix[nr][nc] > matrix[i][j]){
                    max_neighbor = max(max_neighbor, dfs(nr,nc,dp,matrix));

                }
            }
            int result = 1 + max_neighbor;
            dp[i][j] = result;
            return dp[i][j];
    }

    

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col,0));

        int global_max = -1;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dp[i][j]==0){
                    global_max = max(global_max,dfs(i,j,dp,matrix));
                }
            }
        }
        return global_max;
    }
};
