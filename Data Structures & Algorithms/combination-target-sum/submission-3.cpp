class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> subset;

        dfs(res, subset, 0, nums, target);

        return res;
        
    }

    void dfs(vector<vector<int>> & res, vector<int>& subset, int i, vector<int>& nums, int target){

        if(target == 0){
            res.push_back(subset);
            return;
        }

        if(target< 0 || i >= nums.size()){
            return;
        }

        subset.push_back(nums[i]);
        dfs(res,subset,i,nums,target-nums[i]);

        subset.pop_back();
        dfs(res,subset,i+1,nums,target);
    }
};
