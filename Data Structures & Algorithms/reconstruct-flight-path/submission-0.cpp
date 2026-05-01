class Solution {
public:
    vector<string> ans;
    unordered_map<string,vector<string>> adj;

    vector<string> dfs(string s){
      while(!adj[s].empty()){
        string a = adj[s].back();
        adj[s].pop_back();
        dfs(a);
      }
      ans.push_back(s);
      return ans;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& t : adj){
            sort(t.second.begin(),t.second.end(),greater<string>());
        }

        dfs("JFK");

        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
