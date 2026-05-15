class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> curSubset;
        helper(0,nums,curSubset,res);
        return res;
        
    }

    void helper(int i, const vector<int>& nums, vector<int>& curSubset, vector<vector<int>>& res){

        if(i >= nums.size()){
            res.push_back(vector<int>(curSubset));
            return;
        }

        curSubset.push_back(nums[i]);
        helper(i+1, nums, curSubset, res);

        curSubset.pop_back();
        helper(i+1, nums, curSubset, res);

    }
};
