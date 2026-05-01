class Solution {
public:

    string encode(vector<string>& strs) {
        string en = "";
        for(string s: strs){
            en += to_string(s.size()) + "#" + s;

        }
        return en;

    }

    vector<string> decode(string s) {
        vector<string> de;
        int i = 0;
        while(i<s.size()){
            int j = s.find('#',i);
            int l = stoi(s.substr(i , j - i));
            string st = s.substr(j+1,l);
            de.push_back(st);
            i = j + 1 + l;
        }
        return de;
    }
};
