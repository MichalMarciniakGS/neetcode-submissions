class Solution {
public:
    int findMin(vector<int> &nums) {

        int L=0, R=nums.size()-1;
        int res = nums[0];

        while(L<=R){
            
            if(nums[L] < nums[R]){
                return nums[L];
            }

            int mid = L + (R-L)/2;
            res = min(res, nums[mid]);

            // [6,1,2,3,4,5]
            
            // [3,4,5,6,1,2]

            if(nums[mid] < nums[L]){
                R = mid;
            }else{
                L = mid+1;
            }

        }
        return res;
        
    }
};
