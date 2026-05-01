class Solution {
public:
    // Change 1: Vectors ko '&' (Reference) se pass karo
    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion){
        
        // 1. Pehle check: Kya hum gol ghoom ke wapas aa gaye?
        if(inRecursion[i] == true) return true; // CYCLE FOUND!
        
        // 2. Doosra check: Kya ye node pehle hi safe prove ho chuka hai?
        if(visited[i] == true) return false; // No cycle here

        // 3. Mark current node
        visited[i] = true;
        inRecursion[i] = true;

        // 4. Neighbors par jao
        for(auto& n : adj[i]){
            // Change 2: Recursive call ka result check karo
            if(dfs(n, adj, visited, inRecursion) == true) {
                return true; // Agar aage cycle mili, toh turant return true
            }
        }

        // 5. Backtrack: Wapas jate hue inRecursion se hata do
        inRecursion[i] = false;
        return false; // Sab safe hai
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Graph construction aapka sahi tha!
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }   

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        // Change 3: Loop 'numCourses' tak chalana chahiye, prerequisites.size() tak nahi
        // (Kyunki ho sakta hai kuch courses ke prerequisites na ho par wo exist karte ho)
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == false){
                // Change 4: DFS call karo aur check karo
                if(dfs(i, adj, visited, inRecursion) == true) {
                    return false; // Question ne pucha "Can Finish?", agar cycle hai toh FALSE
                }
            }
        }
        return true; // Cycle nahi mili, sab finish kar sakte hain
    }
};