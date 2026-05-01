class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;

        string longest = "";

        for(int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            string odd = expandAroundCenter(s, i, i);

            // Even length palindrome
            string even = expandAroundCenter(s, i, i + 1);

            if(odd.length() > longest.length())
                longest = odd;

            if(even.length() > longest.length())
                longest = even;
        }

        return longest;
    }
};
