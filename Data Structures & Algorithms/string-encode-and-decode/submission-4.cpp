class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0;i<strs.size();i++){
            int l = strs[i].length();
            s += to_string(l) + "#" + strs[i] ;

        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
       while(i < s.length()){
        int j = i;

        while(s[j] != '#'){
            j++;
        }
        int l = stoi(s.substr(i,j-i));
            
            strs.push_back(s.substr(j+1,l));
            i = j+1+l;
        
       }
        return strs;

    }
};
