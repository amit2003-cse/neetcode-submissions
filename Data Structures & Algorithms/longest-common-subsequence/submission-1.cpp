class Solution {
public:
    int solve(int index_1,int index_2,vector<vector<int>>& memo,string& text1, string& text2){
        if(index_2 >= text2.length() || index_1 >= text1.length()) return 0;

        if(memo[index_1][index_2] != -1) return memo[index_1][index_2];

        if(text1[index_1] == text2[index_2]){
            return memo[index_1][index_2] = 1 + solve(index_1 + 1, index_2+1, memo, text1, text2);
        }else{
            return memo[index_1][index_2] = max(solve(index_1, index_2+1, memo, text1, text2),solve(index_1 + 1, index_2, memo, text1, text2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length(),vector<int>(text2.length(), -1));
        return solve(0,0,memo,text1,text2);
    }
};
