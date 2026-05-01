class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& inRecursion,vector<int>& order){
        if(inRecursion[i]==true) return true;
        if(visited[i]==true) return false;
        
        visited[i]=true;
                inRecursion[i]=true;
        for(auto& n:adj[i]){
            if(visited[n]==false){
                
                if(dfs(n,adj,visited,inRecursion,order)==true) return true;
            }else if(inRecursion[n]==true){
                return true;
            }
        }
        inRecursion[i] = false;
        order.push_back(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);

        vector<int> order;

        for(int i=0;i<numCourses;i++){
            if(visited[i]==false){
                
                
                if(dfs(i,adj,visited,inRecursion,order)){return {};}
                
            }else if(inRecursion[i]==true){
                return {};
            }
        }
        reverse(order.begin(),order.end());
        return order;
        
    }
};
