class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left=0, maxfreq=0, maxlen=0;

        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq,freq[s[right]-'A']);
        
        
        int window_size = (right-left) + 1;
        if(window_size - maxfreq > k){
            freq[s[left]-'A']--;
            left++;
        }
        maxlen = max(maxlen,(right-left) + 1);
        }
        return maxlen;
    }
};
