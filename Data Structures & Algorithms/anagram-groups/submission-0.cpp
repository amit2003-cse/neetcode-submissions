class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string s:strs){
            string str=s;
            sort(str.begin(),str.end());
            map[str].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& pair:map){
            result.push_back(pair.second);
        }
        return result;
        
    }
};
