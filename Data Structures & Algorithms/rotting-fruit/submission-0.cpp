class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int min = 0;
        queue<pair<int,int>> q;

        int fresh_count = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_count += 1;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
        while(!q.empty() && fresh_count>0){
            int s=q.size();

            for(int i=0;i<s;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int d=0;d<4;d++){
                    int newR = row + dr[d];
                    int newC = col + dc[d];

                    if(newR<0 || newR >= r || newC <0 || newC >= c || grid[newR][newC]==0) continue;

                    if(grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        q.push({newR,newC});
                        fresh_count -= 1;
                        
                    }

                }
               
                 
            }
            min +=1;
            
        }
        if(fresh_count != 0 ) return -1;
        return min;

    }
};
