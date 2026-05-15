class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> curComb;

        helper(0,nums,target,curComb,res);

        return res;
        
    }

    void helper(int i, const vector<int>& nums, int target, vector<int>& curComb, vector<vector<int>>& res){

        if(target == 0){
            res.push_back(curComb);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        curComb.push_back(nums[i]);
        helper(i, nums, target-nums[i], curComb, res);

        curComb.pop_back();
        helper(i+1, nums, target, curComb, res);

    }
};
