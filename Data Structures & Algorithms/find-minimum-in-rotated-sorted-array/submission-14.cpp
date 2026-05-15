class Solution {
public:
    int findMin(vector<int> &nums) {

        int L=0;
        int R=nums.size()-1;

        while(L<R){

            int mid = L+(R-L)/2;

            if(nums[R] < nums[mid]){
                L = mid+1;
            }
            else{
                R = mid;
            }


        }
        return nums[L];

        return -1;
        
    }
};
