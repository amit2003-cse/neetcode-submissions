class Solution {
public:

    unordered_set<int> map;
    int longestConsecutive(vector<int>& nums) {
        for(auto& n :nums){
            map.insert(n);
        }
        int max_count = 0;
        
        for(auto& n: map){
            int count = 0;
            if(map.find(n-1) == map.end()){
                count +=1;
                int curr_num = n;
               while(map.count(curr_num +1)){
                curr_num += 1;
                count += 1;
               }
            }
            max_count = max(count,max_count);
        }
        return max_count;
        
        
    }
};
