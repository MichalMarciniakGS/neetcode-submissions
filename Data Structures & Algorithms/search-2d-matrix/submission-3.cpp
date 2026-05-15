class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int columns = matrix[0].size();

        int top = 0;
        int bot = rows-1;

        while (top <= bot){
            int curRow = (top+bot)/2;

            if(matrix[curRow][0] > target){
                bot = curRow - 1;
            }
            else if(matrix[curRow][columns-1] < target){
                top = curRow + 1;
            }
            else{
                break;
            }
        }

        if (!(top <= bot)){
            return false;
        }


            int L = 0;
            int R = columns-1;
            int curRow = (top + bot)/2;

            while(L <= R){
                int mid = (L+R)/2;
                if(matrix[curRow][mid] > target){
                    R = mid - 1;
                }
                else if(matrix[curRow][mid] < target){
                    L = mid + 1;
                }
                else{
                    return true;
                }
            }
            return false;
        }
    };
