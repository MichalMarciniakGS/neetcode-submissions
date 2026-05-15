class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> picked(nums.size(), false);
        vector<int> curPer;

        helper(0,picked,curPer,nums);

        return res;
        
    }

    void helper(int i, vector<bool>& picked, vector<int>& curPer, const vector<int>& nums){

        if(curPer.size() == nums.size()){
            res.push_back(curPer);
            return;
        }

        for(int j=0; j<nums.size(); j++){

            if(!picked[j]){
                curPer.push_back(nums[j]);
                picked[j] = true;
                helper(j+1,picked,curPer,nums);
                curPer.pop_back();
                picked[j] = false;
                // helper(j+1, picked, curPer, nums);
            }

        }

    }
};
