class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(auto&s:strs){
            encode += to_string(s.length()) + '#' + s;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string>* decode = new vector<string>();

        int i =0;
        while(i<s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            decode->push_back(s.substr(j+1,len));
            i = j + 1 + len;
        }
        return *decode;
    }
};
