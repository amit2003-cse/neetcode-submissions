class Solution {
public:
    void solve(int i, string digits,vector<string>& result, string& curr, unordered_map<char,string>& map){
        
        

        if(curr.length() == digits.length()) {
            result.push_back(curr);
            return;
            };

        char a = digits[i];
        string b = map[a];
        for(int j = 0;j<b.length();j++){
            curr += b[j];
            solve(i+1,digits, result, curr, map);
            curr.pop_back();
            
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> map;

        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        vector<string> result;
        string curr = "";
        if(digits.length() == 0) return result;
        
        solve(0,digits, result, curr, map);
        return result;
    }
};
