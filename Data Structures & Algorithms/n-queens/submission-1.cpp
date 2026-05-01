class Solution {
public:
    // Engine mein ab humne apni 3 "Memory" (arrays) bhi pass ki hain
    void backtrack(int row, vector<string>& board, vector<vector<string>>& output, int n, 
                   vector<bool>& colCheck, vector<bool>& leftDiagCheck, vector<bool>& rightDiagCheck) {
        
        // 1. Base Case: Saari rows khatam
        if (row == n) {
            output.push_back(board);
            return;
        }

        // 2. Har column par try karo
        for (int col = 0; col < n; col++) {
            
            // O(1) Check: Agar column aur dono diagonals khali hain (false hain)
            if (!colCheck[col] && !leftDiagCheck[row - col + n - 1] && !rightDiagCheck[row + col]) {
                
                // STEP A: Action (Place Queen & Update Memory)
                board[row][col] = 'Q';
                colCheck[col] = true;
                leftDiagCheck[row - col + n - 1] = true;
                rightDiagCheck[row + col] = true;
                
                // STEP B: Recurse (Agli row ke liye call)
                backtrack(row + 1, board, output, n, colCheck, leftDiagCheck, rightDiagCheck);
                
                // STEP C: Undo (Remove Queen & Clear Memory)
                board[row][col] = '.'; 
                colCheck[col] = false;
                leftDiagCheck[row - col + n - 1] = false;
                rightDiagCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> board(n, string(n, '.'));
        
        // Memory arrays initialize kiye
        vector<bool> colCheck(n, false);
        vector<bool> leftDiagCheck(2 * n - 1, false);
        vector<bool> rightDiagCheck(2 * n - 1, false);
        
        // Engine start kiya
        backtrack(0, board, output, n, colCheck, leftDiagCheck, rightDiagCheck);
        
        return output;
    }
};