class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<pair<string,int>> q;
        
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            
            q.pop();

            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(char e='a';e<='z';e++){
                    word[i]=e;
                    

                    if(st.find(word)!= st.end()){
                        if(endWord == word) return count+1;
                        q.push({word,count+1});
                        st.erase(word);
                    }
                    word[i] = original;

                }
            }
            
        }
        return 0;
    }
};
