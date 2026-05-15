class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;

        helper(0, res, nums, temp);

        return res;

    }

    void helper(int i, vector<vector<int>>& res, const vector<int>& nums, vector<int> temp){

        if(i >= nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(i+1, res, nums, temp);

        temp.pop_back();
        helper(i+1, res, nums, temp);
    }
};
