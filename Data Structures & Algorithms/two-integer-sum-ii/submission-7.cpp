class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        for(int i=1;i<=numbers.size();i++){
            int comp = target - numbers[i-1];
            if(map.count(comp)){
                return {map[comp],i};
            }
            map[numbers[i-1]] = i;
           
        }
         return {};
        
    }
};
