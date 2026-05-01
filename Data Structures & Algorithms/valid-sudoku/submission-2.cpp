class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
            if(c =='.') continue;
            
            if(row[i].count(c)) return false;
            row[i].insert(c);
            if(col[j].count(c)) return false;
            col[j].insert(c);
            int boxIndex = (i/3) * 3 + (j/3);
            if(box[boxIndex].count(c)) return false;
            box[boxIndex].insert(c);
            }
            
        }
        return true;
    }
};
