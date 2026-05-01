class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> seen;

        for(char n:s){
            seen[n]++;
        }

        for(char n:t){
            seen[n]--;
            if(seen[n]<0){
                return false;
            }
        }
        return true;
    }
};
