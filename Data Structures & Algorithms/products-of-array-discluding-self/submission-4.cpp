class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> numsL(nums.size(),1);
        vector<int> numsR(nums.size(),1);
        vector<int> res(nums.size());

        // [1,2,4,6] org
        // [1,]

        for(int i=1; i<nums.size(); i++){
            numsL[i] = numsL[i-1] * nums[i-1];
        }

        for(int i=nums.size()-2; i>=0; i--){
            numsR[i] = numsR[i+1] * nums[i+1];
        }

        for(int i=0; i<nums.size(); i++){
            res[i] = numsL[i] * numsR[i];
        }

        return res;

    }
};
