class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row,vector<bool>(col,(false)));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        

        pq.push({grid[0][0],{0,0}});
        vis[0][0] = true;

        int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r == row-1 && c == col -1) return t;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
            if(nr>=0 && nr<row && nc>=0 && nc<col && !vis[nr][nc]){
                vis[nr][nc] = true;
            int max_time = max(t,grid[nr][nc]);

                pq.push({max_time,{nr,nc}});
            }}

            
        }
        return 0;
    }
};
