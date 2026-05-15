class NumMatrix {

    //c0c1c2c3
    // 0 0 0 0   r0
    // 0 1 2 2   r1
    // 0 3 3 1   r2
    // 0 4 5 5   r3

    //c0c1c2
    // 1 2 2   r0
    // 3 3 1   r1
    // 4 5 5   r3

    vector<vector<int>> cumulativeSumMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        int rS = matrix.size();
        int cS = matrix[0].size();

        cumulativeSumMatrix.assign(rS+1, vector<int>(cS+1, 0));

        for(int i=0; i<rS; i++){
            int prefix = 0;
            for(int j=0; j<cS; j++){
                int above = cumulativeSumMatrix[i][j+1];
                prefix += matrix[i][j];
                cumulativeSumMatrix[i+1][j+1] = prefix + above;
            }

        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        row1++;col1++;row2++;col2++;
        int bottomRight = cumulativeSumMatrix[row2][col2];
        int above = cumulativeSumMatrix[row1-1][col2];
        int bottomLeft = cumulativeSumMatrix[row2][col1-1];
        int missingLeftTop = cumulativeSumMatrix[row1-1][col1-1];

        return bottomRight-above-bottomLeft+missingLeftTop;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */