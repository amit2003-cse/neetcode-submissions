class Solution {
    int solve(int index, bool can_buy, vector<int>& prices,vector<vector<int>>& memo){
        if(index >= prices.size()) return 0;
        if(memo[index][can_buy] != -1) return memo[index][can_buy];

        if(can_buy) {
            int buy_day = -prices[index] + solve(index+1,false,prices,memo);
            int skip_day = 0 + solve(index + 1, true, prices,memo);
            return memo[index][can_buy] = max(buy_day,skip_day);
        }else{
            int sell_day = prices[index] + solve(index + 2,true,prices,memo);
            int skip_day = 0 + solve(index + 1,false,prices,memo);
            return memo[index][can_buy] = max(sell_day,skip_day);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(),vector<int>(2,-1));
        return solve(0,true,prices,memo);
    }
};
