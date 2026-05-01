class Solution {
public:
    
    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0;  
        int prev2 = 0;  
        
        for (int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            
            int curr = max(pick, notPick);
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];  // Edge case
        
        // Case 1: Exclude last house
        int case1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Exclude first house
        int case2 = robLinear(nums, 1, n - 1);
        
        return max(case1, case2);
    }
};
