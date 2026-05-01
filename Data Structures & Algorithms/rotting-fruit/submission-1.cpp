class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time = 0;
        int row = grid.size(), col = grid[0].size();
        int fresh = 0;

        // initial scan
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        // BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }

            time++;  // ek level complete
        }

        return (fresh == 0) ? time : -1;
    }
};