class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> curComb;
        helper(0,curComb, nums,target);
        return res;
        
    }

    void helper(int i, vector<int>& curComb, const vector<int>& nums, int target){

        if(target == 0){
            res.push_back(curComb);
            return;
        }

        if(i >= nums.size() || target < 0){
            return;
        }

        curComb.push_back(nums[i]);
        helper(i,curComb, nums, target-nums[i]);

        curComb.pop_back();
        helper(i+1,curComb,nums,target);

    }
};
