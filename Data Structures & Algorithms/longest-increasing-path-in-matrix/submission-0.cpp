class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxPath = 1; // at least the cell itself
        
        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if (ni >= 0 && nj >= 0 && ni < m && nj < n 
                && matrix[ni][nj] > matrix[i][j]) {
                
                maxPath = max(maxPath, 1 + dfs(matrix, ni, nj));
            }
        }
        
        return dp[i][j] = maxPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }
        
        return result;
    }
};