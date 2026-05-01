class Solution {
public:

    void generateHelper(int open,int close,string curr, vector<string>& result){
        if(open == 0 && close == 0){
            result.push_back(curr);
            return;
        }

        if(open>0){
            generateHelper(open - 1,close,curr + "(",result);
        }

        if(close>open){
            generateHelper(open, close -1 , curr + ")", result);
        }



    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateHelper(n,n,"",result);
        return result;
        
    }
};
