class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        vector<int> subset;

        dfs(result, subset, 0, nums, target);

        return result;

    }

    void dfs(vector<vector<int>>& result, vector<int>& subset, int i, vector<int>& nums, int target){

        if(target==0){
            result.push_back(subset);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        subset.push_back(nums[i]);
        dfs(result, subset, i, nums, target - nums[i]);
        subset.pop_back();
        dfs(result, subset, i+1, nums, target);
    }
};
