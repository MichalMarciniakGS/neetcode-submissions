class Solution {

    unordered_map<string,int> memo;

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return helper(0,0,nums,target);      
        
    }

    int helper(int i, int total, const vector<int>& nums, int target){

        if(i >= nums.size()){
            return total == target;
        }

        string curKey = to_string(i) + "," + to_string(total);

        if(memo.count(curKey)){
            return memo[curKey];
        }

        memo[curKey] = helper(i+1, total+nums[i], nums, target) + helper(i+1, total-nums[i], nums, target);
        return memo[curKey];


    }
};