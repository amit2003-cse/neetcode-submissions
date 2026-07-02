class Solution {
   public:
    int solve(int index, int curr_sum, vector<vector<int>>& memo, int amount, vector<int>& coins) {
        if (curr_sum > amount) return 0;
        if (index == coins.size()) return 0;
        if (curr_sum == amount) return 1;
        if (memo[index][curr_sum] != -1) return memo[index][curr_sum];

        int take_it = solve(index, curr_sum + coins[index],memo, amount, coins);
        int loose_it = solve(index + 1, curr_sum,memo, amount, coins);

        memo[index][curr_sum] = take_it + loose_it;

        return take_it + loose_it;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));

        return solve(0, 0, memo, amount, coins);
    }
};
