class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // [1,2,4,6] org

        // [48,24,12,8] res

        // [1,1,2,8] from left

        // [48,24,6,1] from right

        vector<int> res(nums.size());
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);

        for(int i=1; i<nums.size(); i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i=nums.size()-2; i>=0; i--){
            right[i] = right[i+1] * nums[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            res[i] = left[i] * right[i];
        }

        return res;

    }
};
