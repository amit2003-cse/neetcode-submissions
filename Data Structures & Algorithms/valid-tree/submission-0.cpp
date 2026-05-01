class Solution {
public:
    unordered_set<int> visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= n-1) return false;

        vector<vector<int>> adj(n);
        int u,v;
        for(auto& edge: edges){
            u=edge[0];
            v=edge[1];
            adj[u].push_back(v);
        adj[v].push_back(u);
        }
        

        queue<int> q;
        q.push(0);
        visit.insert(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& neighbor : adj[node]){
                if(visit.find(neighbor) == visit.end()){
                    visit.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        if(visit.size() == n) return true;
        return false;
    }
};
