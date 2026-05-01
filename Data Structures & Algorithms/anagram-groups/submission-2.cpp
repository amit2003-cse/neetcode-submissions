class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> map;

        for(auto s: strs){
            string sortedstr = s;
            sort(sortedstr.begin(),sortedstr.end());
            map[sortedstr].push_back(s);
        }
        vector<vector<string>> result;

        for(auto it : map){
            result.push_back(it.second);
        }
        return result;
        
    }
};
