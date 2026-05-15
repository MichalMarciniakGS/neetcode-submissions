class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        

        for(auto vec : matrix){
            int L = 0;
            int R = vec.size()-1;

            while(L <= R){
                int mid = (L+R)/2;

                if(target < vec[mid]){
                    R = mid - 1;
                }
                else if(target > vec[mid]){
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
