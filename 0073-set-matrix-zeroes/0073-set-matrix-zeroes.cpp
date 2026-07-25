class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> row(n, 1);
        vector<int> col(m, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]== 0){
                    row[i]= 0;
                    col[j]= 0;
                }
            }
        }
        for(int k=0; k<n; k++){
            if(row[k]== 0)
                for(int l=0; l<m; l++)
                    matrix[k][l]= 0;
        }
        for(int k=0; k<m; k++){
            if(col[k]== 0)
                for(int l=0; l<n; l++)
                    matrix[l][k]= 0;
        }
    }
};