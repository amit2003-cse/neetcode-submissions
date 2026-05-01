class Solution {
public:
    
    void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis){
        
        for(auto& neighbour : adj[i]){
            if(vis[neighbour]==false){
                vis[neighbour]=true;
                dfs(neighbour,adj,vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n,false);
        int count =0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                count += 1;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
