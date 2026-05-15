class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {


        vector<int> curSub;
        helper(0,nums,curSub);
        return res;

    }

    void helper(int i, const vector<int>& nums, vector<int>& curSub){

        if(i >= nums.size()){
            res.push_back(curSub);
            return;
        }

        curSub.push_back(nums[i]);
        helper(i+1, nums, curSub);

        curSub.pop_back();
        helper(i+1, nums, curSub);

    }
};
