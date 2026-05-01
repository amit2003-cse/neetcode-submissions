class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> st{{')','('},{'}','{'},{']','['}};
        stack<char> open_bracket;
        for(char c: s){
            if(st.find(c) != st.end() ){
                if(!open_bracket.empty() && open_bracket.top()== st[c])
                open_bracket.pop();
                else
            return false;
            }
            else
            open_bracket.push(c);
            
        }
        return open_bracket.empty();
        
    }
};
