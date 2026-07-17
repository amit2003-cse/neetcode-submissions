class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(n,vector<bool>(n,false));

        pq.push({grid[0][0],0,0});
        visited[0][0] = true;

        int max_height_so_far = 0;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            int height = curr[0];
            int row = curr[1];
            int col = curr[2];

           

            

            max_height_so_far = max (max_height_so_far, height);

            if(row==n-1 && col == n-1) return max_height_so_far;

            for(int i=0;i<4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false){
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc],nr,nc});
                }
            }
             
        }

        return 0;
    }
};
