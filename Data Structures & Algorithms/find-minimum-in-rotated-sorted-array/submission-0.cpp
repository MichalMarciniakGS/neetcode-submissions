class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int L=0, R=nums.size()-1;

        while(L <= R){

            if(nums[L] < nums[R]){
                res = min(res, nums[L]);
                break;
            }
            int mid = L + (R-L)/2;
            res = min(res, nums[mid]);

            if(nums[mid] >= nums[L]){
                L = mid+1;
            }else{
                R = mid-1;
            }
        }
        return res;
        
    }
};
