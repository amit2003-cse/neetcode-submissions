class PrefixTree {
public:
    
    PrefixTree* children[26];
    bool isEndOfWord;

    PrefixTree() {
        isEndOfWord = false;
        for(int i=0;i<26;i++){
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        PrefixTree* curr = this;

        for(char c : word){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new PrefixTree();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
         PrefixTree* curr = this;
        for(auto& c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        if(!curr->isEndOfWord ) return false;
        else return true;
    }
    
    bool startsWith(string prefix) {
         PrefixTree* curr = this;
        for(auto& c : prefix) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
