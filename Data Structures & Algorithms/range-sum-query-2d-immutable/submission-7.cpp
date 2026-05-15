class NumMatrix {

    vector<vector<int>> preMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        // 0 0 0 0
        // 0 1 2 2
        // 0 3 3 5

        int rS = matrix.size();
        int cS = matrix[0].size();

        preMatrix.assign(rS+1, vector<int>(cS+1, 0));

        for(int r = 0; r<rS; r++){
            int preSum = 0;
            for(int c = 0; c<cS; c++){
                preSum += matrix[r][c];
                int above = preMatrix[r][c+1];
                preMatrix[r+1][c+1] = preSum+above;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;

        int bottomRight = preMatrix[row2][col2];
        int above = preMatrix[row1-1][col2];
        int left = preMatrix[row2][col1-1];
        int topLeftAdd = preMatrix[row1-1][col1-1];

        return bottomRight-above-left+topLeftAdd;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */