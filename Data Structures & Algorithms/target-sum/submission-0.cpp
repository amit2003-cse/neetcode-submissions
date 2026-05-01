#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge cases
        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int subsetSum = (target + totalSum) / 2;

        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = subsetSum; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[subsetSum];
    }
};