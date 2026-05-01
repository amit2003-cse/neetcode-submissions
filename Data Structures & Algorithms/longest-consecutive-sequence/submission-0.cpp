class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int longst = 0;

        for(int n:nums){
            if(set.find(n-1) == set.end()){
            int curr = n;
            int currst = 1;
            

            while(set.find(curr+1) != set.end()){
                curr++;
                currst++;
            }
            
            longst = max(longst,currst);
            }
        }
        return longst;
        
        
    }
};
