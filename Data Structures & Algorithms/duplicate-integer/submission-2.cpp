class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num:nums){
            if(seen.count(num)){
                return true;
            }
            else{
                seen.insert(num);
            }
        }
        return false;

    }
};
