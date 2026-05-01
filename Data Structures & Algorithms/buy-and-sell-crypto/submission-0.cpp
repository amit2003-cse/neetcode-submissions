class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_pri = INT_MAX;
        int max_pri = 0;

        for(int i = 0; i<prices.size();i++){
            if(prices[i]<min_pri)
            min_pri = prices[i];
            max_pri = max(max_pri, prices[i] - min_pri);
        }
        return max_pri;
        
    }
};
