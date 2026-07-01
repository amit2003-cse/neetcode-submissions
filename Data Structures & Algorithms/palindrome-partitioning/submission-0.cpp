class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(int index, string& s, vector<string>& curr_path, vector<vector<string>>& result){
        if(index == s.length()){
            result.push_back(curr_path);
            return;
        }

        for(int i=index;i<s.length();i++){
            string substring = s.substr(index,i - index + 1);

            if(isPalindrome(s,index,i)){
                curr_path.push_back(substring);

                solve(i + 1, s, curr_path,result);

                curr_path.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr_path;
        vector<vector<string>> result;

        solve(0,s,curr_path,result);

        return result;
    }
};
