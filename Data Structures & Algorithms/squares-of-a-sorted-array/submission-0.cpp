class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for(auto& n:nums){
            result.push_back(pow(n,2));
        }
        sort(result.begin(),result.end());
        return result;
    }
};