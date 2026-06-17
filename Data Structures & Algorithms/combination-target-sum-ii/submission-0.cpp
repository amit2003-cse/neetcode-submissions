class Solution {
public:
    void solve(int i, int target, vector<int>& current, vector<vector<int>>& result,vector<int>& candidates){
        if(target == 0){ 
            result.push_back(current);
            return;
        }
        
        if(i == candidates.size() || target<0){
            return;
        }
        for(int ind = i; ind < candidates.size(); ind++) {
    
    
    if(ind > i && candidates[ind] == candidates[ind - 1]) {
        continue; 
    }
     current.push_back(candidates[ind]); // DO
    solve(ind + 1, target - candidates[ind],current, result, candidates); // RECURSE
    current.pop_back();
    
    }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> current;
        vector<vector<int>> result;

        sort(candidates.begin(),candidates.end());

        solve(0,target,current,result,candidates);

        return result;
    }
};
