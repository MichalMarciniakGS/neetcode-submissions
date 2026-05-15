class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result{};
        vector<int> cur;

        dfs(0, cur, 0, result, nums, target);

        return result;

    }

    void dfs(int i, vector<int> cur, int total, vector<vector<int>>& result,
     vector<int>& nums, int target){

        if(target == total){
            result.push_back(cur);
            return;
        }

        if(i >= nums.size()){
            return;
        }

        if(total > target){
            return;
        }

        cur.push_back(nums[i]);
        dfs(i, cur, total + nums[i], result, nums, target);

        cur.pop_back();
        dfs(i+1,cur,total, result, nums, target);


     }





















    // void dfs(int i, vector<int> cur, int total,
    //  vector<vector<int>>& result, vector<int>& nums, int target){

    //     if(total == target){
    //         result.push_back(cur);
    //         return;
    //     }

    //     if(i >= nums.size() || total > target){
    //         return;
    //     }

    //     cur.push_back(nums[i]);
    //     dfs(i,cur,total + nums[i], result, nums, target);

    //     cur.pop_back();
    //     dfs(i+1,cur,total,result,nums,target);


    // }
};
