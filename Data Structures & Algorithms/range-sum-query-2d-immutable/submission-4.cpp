class NumMatrix {

    vector<vector<int>> prefixSums;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        int rSize = matrix.size();
        int cSize = matrix[0].size();

        prefixSums.assign(rSize+1, vector<int>(cSize+1, 0));

        for(int r=0; r<rSize; r++){
            int prefix = 0;
            for(int c=0; c<cSize; c++){
                prefix += matrix[r][c];
                int above = prefixSums[r][c+1];
                prefixSums[r+1][c+1] = prefix+above;
            }
        }


        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;

        int bottomRight = prefixSums[row2][col2];
        int above = prefixSums[row1-1][col2];
        int bottomLeft = prefixSums[row2][col1-1];
        int topLeft = prefixSums[row1-1][col1-1];

        return bottomRight-above-bottomLeft+topLeft;

        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */