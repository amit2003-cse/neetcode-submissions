class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int i=0; i<9;i++){
            for(int j=0; j<9;j++){
                char num = board[i][j];

                if(num == '.')  continue;

                if(row[i].count(num)) return false;
                row[i].insert(num);

                if(col[j].count(num)) return false;
                col[j].insert(num);

                int boxIndex = (i/3) * 3 + (j/3);
                if(box[boxIndex].count(num)) return false;
                box[boxIndex].insert(num);

            }
        }

        return true;
        
        
    }
};
