class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char,int> map;

        for(auto a:s){
            map[a]++;
        }
        for(auto a:t){
            map[a]--;
        }
        for(auto a:map){
            if(a.second != 0)
            return false;
        }
        return true;
    }
};
