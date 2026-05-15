class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubsets;
        vector<int> curSubset;
        helper(0,nums,curSubset,allSubsets);
        return allSubsets;
        
    }

    void helper(int i, const vector<int>& nums, vector<int>& curSubset, vector<vector<int>>& allSubsets){

        if( i >= nums.size()){
            allSubsets.push_back(vector<int>(curSubset));
            return;
        }

        //include nums[i]:
        curSubset.push_back(nums[i]);
        helper(i+1, nums, curSubset, allSubsets);

        //not include nums[i]:
        curSubset.pop_back();
        helper(i+1, nums, curSubset, allSubsets);
    }
};
