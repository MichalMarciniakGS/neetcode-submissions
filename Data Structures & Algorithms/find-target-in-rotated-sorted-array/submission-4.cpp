class Solution {
public:
    int search(vector<int>& nums, int target) {

        int L=0;
        int R=nums.size()-1;

        while(L <= R){

            int mid = L + (R-L)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[L] == target){
                return L;
            }

            if(nums[R] == target){
                return R;
            }

            if(nums[mid] >= nums[L]){ //left half is increasing
                if(nums[L] <= target && target < nums[mid]){ //target is on the left side
                    R = mid-1;
                }else{
                    L = mid+1;
                }

            }else{ //right half is increasing
                if(nums[mid] < target && target <= nums[R]){ //target is on the tight side
                    L = mid+1;
                }else{
                    R = mid-1;
                }

            }
        }

        return -1;
        
    }
};
