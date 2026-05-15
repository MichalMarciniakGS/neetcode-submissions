class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result = {};
        vector<int> subset = {};

        dfs(result, nums, 0, subset);

        return result;


    }


    void dfs(vector<vector<int>>& result, vector<int>& nums, int i, vector<int> subset){

        if(i >= nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(result, nums, i+1, subset);

        subset.pop_back();
        dfs(result, nums, i+1, subset);

    }

















    // void dfs(vector<vector<int>>& result, vector<int>& nums, int i, vector<int> subset){


    //     if( i >= nums.size()){
    //         result.push_back(subset);
    //         return;
    //     }

    //     //decision to include nums[i]
    //     subset.push_back(nums[i]);
    //     dfs(result, nums, i+1, subset);

    //     //decision not to include nums[i]
    //     subset.pop_back();
    //     dfs(result, nums, i+1, subset);

    // }
};
