class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        
        // Step 1: Initialize parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Step 2: Process edges
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!unionSet(u, v, parent, rank)) {
                return edge; // Cycle mila, yeh redundant edge hai
            }
        }
        
        return {}; // No redundant edge (shouldn't happen per problem)
    }
    
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }
    
    bool unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv) return false; // Cycle hai
        
        // Union by rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};