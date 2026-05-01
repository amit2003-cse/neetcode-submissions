class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> freq1(26,0), freq2(26,0);
        int left=0;

        for(char c:s1){
            freq1[c-'a']++;
        }
       int window_size = s1.length();

        for(int i=0;i<s2.length();i++){
            freq2[s2[i]-'a']++;

            if(i>=window_size){
                freq2[s2[i-window_size]-'a']--;
            }
            
            if(freq1==freq2) return true;
        }
        return false;
        

    }
};
