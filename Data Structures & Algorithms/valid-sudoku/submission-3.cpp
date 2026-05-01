class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9],col[9],box[9];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                int index = i/3 *3 + j/3;
                int val = board[i][j];
                if(val == '.') continue;
                
                if(row[i].count(val) || col[j].count(val) || box[index].count(val)) return false;

                row[i].insert(val);
                col[j].insert(val);
                box[index].insert(val);
            }
        }
        return true;
        
    }
};
