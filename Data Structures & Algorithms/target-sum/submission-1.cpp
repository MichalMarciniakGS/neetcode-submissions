class Solution {

    // vector<vector<int>> dp;
    unordered_map<string,int> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // totalSum = accumulate(nums.begin(), nums.end(), 0);
        // dp.assign(nums.size(), vector<int>(2*totalSum+1, INT_MIN));

        return helper(0,0,nums,target);
        
    }

    int helper(int i, int total, vector<int> nums, int target){

        if(i == nums.size()){
            return total == target;
        }

        // if(dp[i][total + totalSum] != INT_MIN){
        //     return dp[i][total + totalSum];
        // }
        string key = to_string(i) + "," + to_string(total);

        if(dp.count(key)){
            return dp[key];
        }

        dp[key] = helper(i+1, total + nums[i], nums, target) +
            helper(i+1, total - nums[i], nums, target);

        return dp[key];

    }
};
