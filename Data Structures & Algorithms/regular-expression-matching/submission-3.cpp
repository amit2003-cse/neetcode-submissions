class Solution {
public:
    bool solve(int index_p,int index_s,string& s, string& p,vector<vector<int>>& memo){
        if(index_p == p.length()) return index_s == s.length();
        if(memo[index_p][index_s] != -1) return memo[index_p][index_s];

        bool match = (index_s < s.length() && (s[index_s] == p[index_p] || p[index_p] == '.'));

        if(index_p + 1 < p.length() && p[index_p + 1] == '*'){
            return memo[index_p][index_s] = solve(index_p + 2,index_s,s,p,memo) || (match && solve(index_p, index_s+1,s,p,memo));
        }else{
            return memo[index_p][index_s] = match && solve(index_p+1,index_s+1,s,p,memo);
        }
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo(p.length() + 1,vector<int>(s.length() + 1,-1));
        return solve(0,0,s,p,memo);
    }
};
