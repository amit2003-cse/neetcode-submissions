class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto i:nums){
            if(seen.find(i) != seen.end()){
                return true;
            }
            seen.insert(i);
        }
        return false;

    }
};
