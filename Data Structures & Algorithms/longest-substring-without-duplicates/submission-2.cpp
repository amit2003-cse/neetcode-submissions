class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int Max_len = 0;

        for(int right = 0;right<s.size();right++){
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            Max_len = max(Max_len , right - left + 1);

        }

        return Max_len;
        
    }
};
