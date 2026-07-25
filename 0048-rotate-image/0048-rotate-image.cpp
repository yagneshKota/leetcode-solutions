class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int x= matrix.size();
    for(int i=0; i<x; i++){
        for(int j=i+1; j<x; j++){
            int temp= matrix[i][j];
            matrix[i][j]= matrix[j][i];
            matrix[j][i]= temp;
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<x/2; j++){
            int temp= matrix[i][j];
            matrix[i][j]= matrix[i][x-1-j];
            matrix[i][x-1-j]= temp;
        }
    }
    }
};