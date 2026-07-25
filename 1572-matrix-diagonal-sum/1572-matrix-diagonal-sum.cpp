class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int sum= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j || i==(n-1-j) || (n-1-i)==j)
                    sum += matrix[i][j];
            }
        }
        return sum;
    }
};