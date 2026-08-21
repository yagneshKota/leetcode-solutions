class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i= 0; i< 9; i++){
            bool seen[9] = {};
            for(int j= 0; j< 9; j++){
                if(board[i][j] == '.') continue;
                if(seen[board[i][j]- '1']) return false;
                seen[board[i][j]- '1']= true;
            }
        }
        for(int j= 0; j< 9; j++){
            bool seen[9] = {};
            for(int i= 0; i< 9; i++){
                if(board[i][j] == '.') continue;
                if(seen[board[i][j]- '1']) return false;
                seen[board[i][j]- '1']= true;
            }
        }

        for(int r= 0; r<9 ; r= r+3){
            for(int c= 0; c<9; c= c+3){
                bool seen[9]= {};
                for(int i= r; i< r+3; i++){
                    for(int j= c; j< c+3; j++){
                        if(board[i][j] == '.') continue;
                        if(seen[board[i][j]- '1']) return false;
                        seen[board[i][j]- '1']= true;
                    }
                }
            }
        }
        return true;

    }
};