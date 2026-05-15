class Solution {
public:
    int findMin(vector<int> &nums) {

        int L=0;
        int R=nums.size()-1;
        // int res = nums[0];

        while(L<R){

            // if(nums[L] < nums[R]){
            //     // res = min(res,nums[L]);
            //     break;
            // }

            int mid = L + (R-L)/2;
            // res = min(res,nums[mid]);

            if(nums[mid] < nums[R]){
                R = mid;
            }

            if(nums[R] < nums[mid]){
                L = mid+1;
            }

        }

        return nums[L];
        
    }
};
