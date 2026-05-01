class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row,int col,vector<vector<bool>>& vis){
        
 vis[row][col] = true;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int newR = row + dr[i];
            int newC = col + dc[i];
            if(newR<0 || newR >= grid.size() || newC<0 || newC>=grid[0].size() || grid[newR][newC] == '0'|| vis[newR][newC]) continue;
           
            else if(grid[newR][newC] == '1'){
                vis[newR][newC] = true;
                dfs(grid,newR,newC,vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                 if(grid[i][j]=='1' && !vis[i][j]){
                    count += 1;
                   
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;

    }
};
