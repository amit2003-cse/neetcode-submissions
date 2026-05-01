class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> 
        set(nums.begin(),nums.end());
        int longest=0;
        for(auto&n:nums){
            if(set.find(n-1) == set.end()){
                int curr=1;
                while(set.count(n + curr)){
                    curr++;
                }
                longest = max(curr,longest);
            }
        }
        return longest;
    }
};
