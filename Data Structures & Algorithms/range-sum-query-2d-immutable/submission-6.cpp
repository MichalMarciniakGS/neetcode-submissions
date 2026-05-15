class NumMatrix {

    vector<vector<int>> preSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        int rS = matrix.size();
        int cS = matrix[0].size();

        // 0 0 0 0
        // 0 1 2 3
        // 0 2 3 4

        preSum.assign(rS+1, vector<int>(cS+1, 0));

        for(int r=0; r<rS; r++){
            int curSum = 0;
            for(int c=0; c<cS; c++){
                curSum += matrix[r][c];
                int above = preSum[r][c+1];
                preSum[r+1][c+1] = curSum + above;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = preSum[row2][col2];
        int above = preSum[row1-1][col2];
        int leftBefore = preSum[row2][col1-1];
        int topLeft = preSum[row1-1][col1-1];
        return bottomRight - above - leftBefore + topLeft;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */