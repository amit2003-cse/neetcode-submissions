class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            
            adj[u].push_back({v,t});
        }

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int curr_time = curr.first;
            int u = curr.second;

            if(curr_time > dist[u]) continue;

            for(auto& neighbour : adj[u]){
                int v = neighbour.first;
                int time = neighbour.second;

                if(curr_time + time < dist[v]){
                    dist[v] = curr_time + time;
                    pq.push({dist[v],v});
                }
            }

        }
        // 4. Final Answer Calculate Karo
        int max_time = 0;
        for(int i = 1; i <= n; i++) {
            // Agar koi bhi node tak signal nahi pahuncha
            if(dist[i] == INT_MAX) {
                return -1; 
            }
            // Sabse aakhiri node tak pahunchne ka time dhoondho
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;
    }
};
