class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int r{0}; r<rows; ++r){
            int L = 0;
            int R = cols-1;

            if (target == matrix[r][L] || target == matrix[r][R]){
                return true;
            }

            if(target > matrix[r][L] && target < matrix[r][R]){
                while(L <= R){
                int mid = L + (R-L)/2;

                if(matrix[r][mid] == target){
                    return true;
                }else if(matrix[r][mid] < target){
                    L = mid+1;
                }else{
                    R = mid-1;
                }

                }
            }
        }
        return false;
    }
};
