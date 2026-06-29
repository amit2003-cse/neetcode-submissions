class Solution {
private:
    // 1. Inko Global/Private banaya taaki recursion mein baar-baar memory na lein
    int rows;
    int cols;
    int dRow[4] = {-1, 1, 0, 0}; // Naming clear kar di
    int dCol[4] = {0, 0, -1, 1};

    // 2. Naam 'backtrack' rakha aur 'const string&' use kiya
    bool backtrack(int r, int c, int index, vector<vector<char>>& board, const string& word) {
        
        // Base Case: Success
        if (index == word.length()) return true;

        // Base Case: Failure (Ab rows aur cols pre-calculated hain)
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        // --- DO ---
        char temp = board[r][c];
        board[r][c] = '#';

        // --- RECURSE ---
        for (int i = 0; i < 4; i++) {
            if (backtrack(r + dRow[i], c + dCol[i], index + 1, board, word)) {
                return true;
            }
        }
        
        // --- UNDO ---
        board[r][c] = temp;
        
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // 3. Edge Case: Agar grid hi khali ho
        if (board.empty() || board[0].empty()) return false;
        
        // Sirf ek baar size calculate kiya
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                // Early check: Word ka pehla letter match hona chahiye
                if (board[i][j] == word[0]) {
                    if (backtrack(i, j, 0, board, word)) {
                        return true;
                    }
                }
                
            }
        }
        return false;
    }
};