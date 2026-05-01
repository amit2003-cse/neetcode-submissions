class Solution {
public:

    // isSafe function (Aapko baad mein likhna hoga)
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Yahan attack check hoga
       for(int r=0;r<row;r++){
        if(board[r][col]=='Q') return false;
       }
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }

        r=row;
        c=col;
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
       
        return true;
    }

    // Yeh hamara engine hai
    void backtrack(int row, vector<string>& board, vector<vector<string>>& output, int n) {
        
        // 1. Base Case: Agar hum aakhri row cross kar gaye
        if (row == n) {
            output.push_back(board);
            return;
        }

        // 2. Har column par try karo
        for (int col = 0; col < n; col++) {
            
            if (isSafe(row, col, board, n)) {
                
                // STEP A: Action (Place Queen)
                board[row][col] = 'Q';
                
                // STEP B: Recurse (Agli row ke liye call)
                backtrack(row + 1, board, output, n);
                
                // STEP C: Undo (Backtrack) - Wapas '.' bana do
                board[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> board(n, string(n, '.')); // Khali board set kiya
        
        backtrack(0, board, output, n); // Row 0 se start
        
        return output;
    }
};