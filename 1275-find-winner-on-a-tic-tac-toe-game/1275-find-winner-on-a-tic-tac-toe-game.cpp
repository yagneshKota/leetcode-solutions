class Solution {
public:
    int check(vector<int> game){
        vector<vector<int>> pat= {{0,1,2}, {3,4,5}, {6,7,8},
                                  {0,3,6}, {1,4,7}, {2,5,8},
                                  {0,4,8}, {2,4,6}};
        for(int i=0; i<pat.size(); i++){
            if(game[pat[i][0]]==game[pat[i][1]] &&
               game[pat[i][1]]==game[pat[i][2]] &&
               game[pat[i][0]]==game[pat[i][2]] &&
               game[pat[i][0]]!= -1){
                return game[pat[i][0]];
               }
        }
        return -1;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> game(9, -1);
        bool turn= true;
        int count= 0;
        for(int i=0; i<moves.size(); i++){
            if(turn){
                game[moves[i][0]*3 +moves[i][1]]= 1;
                turn= false;
            }
            else{
                game[moves[i][0]*3 +moves[i][1]]= 0;
                turn= true;
            }
            int c=check(game);
            if(c== 1) return "A";
            else if(c== 0) return "B";
            count++;
        }
        if(count== 9) return "Draw";
        return "Pending";
    }
};