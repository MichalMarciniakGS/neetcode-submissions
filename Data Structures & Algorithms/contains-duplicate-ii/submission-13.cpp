class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int L=0;

        if(k==0){
            return false;
        }

        for(int R=1; R<nums.size(); R++){

            if(R-L > k){
                L++;
            }
            if(nums[L] == nums[R]){
                return true;
            }

        }

        return false;
        
    }
};