class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int r{0}; r < rows; ++r) {
            int L = 0;
            int R = rows * cols - 1;

            while (L <= R) {
                int mid = L + (R - L) / 2;
                int val = matrix[mid / cols][mid % cols];

                if (target == val) {
                    return true;
                } else if (target > val) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }
        return false;
    }
};
