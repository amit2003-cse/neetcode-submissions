class Solution {
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
    vector<string> result;

public:
    void dfs(string airpot){
        while(!graph[airpot].empty()){
            string next_airpot = graph[airpot].top();

            graph[airpot].pop();

            dfs(next_airpot);
        }

        result.push_back(airpot);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto& t : tickets){
            graph[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
