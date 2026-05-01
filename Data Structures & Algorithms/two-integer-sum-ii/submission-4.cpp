class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int,int> map;
        for(int i = 0 ; i<numbers.size();i++){
            int com = target - numbers[i];
            if(map.find(com) != map.end()){
                return {map[com]+1,i+1};
            }
            map[numbers[i]] = i;
        }
        return {};
        
    
    }
};
