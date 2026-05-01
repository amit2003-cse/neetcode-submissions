class Solution {
public:
    

   

    bool canPartition(vector<int>& nums) {
        int total_sum = 0;

        for(auto& n:nums){
            total_sum += n;
        }
        if(total_sum % 2 != 0) return false;

        int target = total_sum/2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(auto& n : nums){
            for(int j = target; j>=n;j--){
                if(dp[j-n] == true) dp[j] = true;
            }
        }
        
        return dp[target];

    }
};
