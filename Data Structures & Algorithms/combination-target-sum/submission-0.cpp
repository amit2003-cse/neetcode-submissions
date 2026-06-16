class Solution {
public:
    void solve(int i, vector<int>& nums,vector<int>& current, vector<vector<int>>& result, int target){
        if(target == 0 ){
            result.push_back(current);
            return;
        }

        if(i == nums.size()|| target <0) {
            return;
        }

        current.push_back(nums[i]);

        solve(i,nums,current, result,target - nums[i]);

        current.pop_back();

        solve(i+1,nums,current, result,target);


    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> current;
        vector<vector<int>> result; 

        solve(0,nums,current,result,target);
        return result;
    }
};
