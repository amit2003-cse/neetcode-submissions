class Solution {
public:
    void solve(int index,vector<int>& nums, int target, int curr_sum,int& max_valid){
        if(index == nums.size()){
            if(curr_sum == target){
            max_valid += 1;
        }
        return;
        }
        
        
        
        solve(index + 1,nums,target,curr_sum + nums[index],max_valid);
        
        solve(index + 1,nums,target,curr_sum - nums[index],max_valid);
        
        
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int max_valid = 0;
        int curr_sum = 0;
        solve(0,nums,target,curr_sum,max_valid);

        return max_valid;
    }
};
