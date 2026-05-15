class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int allSum = accumulate(nums.begin(), nums.end(), 0);

        if(allSum % 2 != 0){
            return false;
        }

        int allSumHalf = allSum/2;

        return helper(0, nums, allSumHalf);

    }

    bool helper(int i, const vector<int>& nums, int allSumHalf){

        if(allSumHalf == 0){
            return true;
        }

        if(i >= nums.size()){
            return false;
        }

        // skip
        bool skipResult = helper(i+1, nums, allSumHalf);
        if(skipResult){
            return true;
        }

        //include
        int newSum = allSumHalf - nums[i];
        if(newSum >= 0){
            return helper(i+1, nums, newSum);
        }

        return false;


    }
};
