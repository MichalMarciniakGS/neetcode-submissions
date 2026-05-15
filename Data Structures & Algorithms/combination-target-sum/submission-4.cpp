class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        vector<int> curV;

        helper(0,res,curV,nums,target);

        return res;

    }

    void helper(int i, vector<vector<int>>& res, vector<int> curV, const vector<int>& nums, int target){

        if(target == 0){
            res.push_back(curV);
            return;
        }

        if(i >= nums.size() || target < 0){
            return;
        }

        curV.push_back(nums[i]);
        helper(i, res, curV, nums, target-nums[i]);

        curV.pop_back();
        helper(i+1, res, curV, nums, target);



    }
};
