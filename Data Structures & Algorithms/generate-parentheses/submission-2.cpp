class Solution {
public:
    vector<string> result;
    void backtrack(string curr,int o,int c,int n){
        if(curr.length()==2*n){
            result.push_back(curr);
            return;
        }
        if(o<n){
            backtrack(curr+"(",o+1,c,n);
        }
        if(c<o){
            backtrack(curr+")",o,c+1,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        
        backtrack("",0,0,n);
        return result;
        
    }
};
