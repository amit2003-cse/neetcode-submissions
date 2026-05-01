class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<prices.size();j++){
                if(j<i){
            int prof = prices[i] - prices[j];
            max_prof = max(prof,max_prof);
                }
            
        }
        }
        return max_prof;
        
    }
};
