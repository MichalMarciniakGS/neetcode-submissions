class Solution {
public:
    int findMin(vector<int> &nums) {

        int L=0;
        int R=nums.size()-1;

        while(L < R){

            int mid = L + (R-L) / 2;

            if(nums[mid] < nums[R]){
                R = mid;
            }
            if(nums[mid] > nums[R]){
                L = mid+1;
            }
        }
        return nums[L];
        
    }
};
