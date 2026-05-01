class Solution {
public:

    string encode(vector<string>& strs) {
        string encod ="";
        for(string i:strs){
            encod += to_string(i.length()) + '#' + i;
        }
        return encod;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1,len);
            result.push_back(word);
            i = 1 + j + len;
        }
        return result;
    }
};
