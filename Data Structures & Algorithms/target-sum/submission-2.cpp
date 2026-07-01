class Solution {
public:
    int solve(int index,vector<int>& nums, int target, int curr_sum,unordered_map<string, int>& map){
        if(index == nums.size()){
            if(curr_sum == target){
            return 1;
        }else{
        return 0;} 
        }

        string key = to_string(index) + "," + to_string(curr_sum);

        if(map.find(key) != map.end()){
            return map[key];
        }
        
        
        
        int plus_way = solve(index + 1,nums,target,curr_sum + nums[index],map);
        
        int minus_way = solve(index + 1,nums,target,curr_sum - nums[index],map);
        
        map[key] = plus_way + minus_way;
        
        return map[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> map;
        int curr_sum = 0;

        int valid_way = 0;

        valid_way = max(valid_way, solve(0,nums,target,curr_sum, map));

        return valid_way;
    }
};
