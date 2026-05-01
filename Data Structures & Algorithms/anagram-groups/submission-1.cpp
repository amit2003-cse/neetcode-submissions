class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        for(auto& s: strs){
            string st = s;
            sort(st.begin(),st.end());
            map[st].push_back(s);
        }
        for(auto &t:map){
            result.push_back(t.second);
        }
        return result;
    }
};
