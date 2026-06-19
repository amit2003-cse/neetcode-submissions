class Solution {
public:
    void solve(vector<int>& freq,vector<int>& nums,vector<int>& current, vector<vector<int>>& result){
        

        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){

                freq[i] = true;

                current.push_back(nums[i]);

                solve(freq, nums,current,result);

                current.pop_back();

                freq[i] = false;
            }
        }

        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<int> freq(nums.size(),false);

        solve(freq, nums,current, result);
        return result;
    }
};

