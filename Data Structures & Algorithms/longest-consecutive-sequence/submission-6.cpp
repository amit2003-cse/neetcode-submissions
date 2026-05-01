class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int maxLen = 0;
        for(int i:hash){
            if(!hash.count(i-1)){
                int currNum = i;
                int currLen = 1;
            
            while(hash.count(currNum +1)){
                currNum += 1;
                currLen ++;
            }
            
            maxLen = max(currLen,maxLen);
            }
        }
        return maxLen;
    }
};
