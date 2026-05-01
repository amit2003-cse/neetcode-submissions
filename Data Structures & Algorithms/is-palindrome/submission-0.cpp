class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";

        for(char c : s){
            if(isalnum(c)){
                clean += tolower(c);
            }
        }
        int left = 0;
        int right = clean.length() - 1;
        while(left<right){
            if(clean[left] != clean[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
