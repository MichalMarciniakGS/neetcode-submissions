class Solution {

    vector<vector<int>> memo;

public:
    bool canPartition(vector<int>& nums) {

        int allSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(allSum % 2 != 0){
            return false;
        }

        int target = allSum/2;
        
        memo.assign(nums.size(), vector<int>(target+1,-1));

        return helper(0,nums,target);

    }

    bool helper(int i, const vector<int>& nums, int target){

        if(target < 0){
            return false;
        }

        if(i >= nums.size()){
            return target == 0;
        }

        if(memo[i][target] != -1){
            return memo[i][target];
        }

        memo[i][target] = helper(i+1,nums,target) || helper(i+1,nums, target-nums[i]);

        return memo[i][target];

    }
};
