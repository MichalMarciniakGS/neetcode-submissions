class Solution {

vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int> curSet;
        helper(0,nums,curSet);
        return res;
        
    }

    void helper(int i, const vector<int>& nums, vector<int>& curSet){

        if(i >= nums.size()){
            res.push_back(curSet);
            return;
        }

        curSet.push_back(nums[i]);
        helper(i+1, nums, curSet);

        curSet.pop_back();
        while(nums.size() > i+1 && nums[i+1] == nums[i]){
            i++;
        }
        helper(i+1, nums, curSet);

    }
};
