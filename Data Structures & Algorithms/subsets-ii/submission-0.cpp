class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curSet;
        helper(0,nums,curSet,res);
        return res;

    }

    void helper(int i, vector<int>& nums, vector<int>& curSet, vector<vector<int>>& res){

        if(i >= nums.size()){
            res.push_back(vector<int>(curSet));
            return;
        }

        curSet.push_back(nums[i]);
        helper(i+1,nums,curSet,res);

        curSet.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        helper(i+1,nums,curSet,res);

    }
};
