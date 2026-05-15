class Solution {

    vector<vector<int>> res;
    unordered_map<int,int> uniMap;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for(auto num : nums){
            uniMap[num]++;
        }

        vector<int> currPerm;

        helper(nums,currPerm);

        return res;
        
    }

    void helper(const vector<int>& nums, vector<int>& currPerm){

        if(currPerm.size() == nums.size()){
            res.push_back(currPerm);
            return;
        }

        for(auto [num,cnt] : uniMap){
            if(cnt>0){
                currPerm.push_back(num);
                uniMap[num]--;
                helper(nums, currPerm);
                currPerm.pop_back();
                uniMap[num]++;
            }
        }

    }
};