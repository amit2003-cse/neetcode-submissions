class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min = INT_MAX;

        for(int n:prices){
            if(n<min){
                min = n;
            }
            else{
                max_profit = max(max_profit,n-min);
            }
        }
        return max_profit;
        
    }
};
