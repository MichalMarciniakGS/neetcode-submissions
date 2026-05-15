class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(auto vec : matrix){
            int L = 0;
            int R = vec.size()-1;

            while(L <= R){
                int mid = (L+R)/2;
                if(vec[mid] > target){
                    R = mid - 1;
                }
                else if(vec[mid] < target){
                    L = mid + 1;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};
