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
            if(map[a] == 0) return false;
            map[a]--;
        }
        
        return true;
    }
};
