class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> curSub;

        helper(0,curSub,nums,res);

        return res;
        
    }

    void helper(int i, vector<int>& curSub, const vector<int>& nums, vector<vector<int>>& res){

        if(i >= nums.size()){
            res.push_back(curSub);
            return;
        }

        curSub.push_back(nums[i]);
        helper(i+1, curSub, nums, res);

        curSub.pop_back();
        helper(i+1, curSub, nums, res);

    }
};
