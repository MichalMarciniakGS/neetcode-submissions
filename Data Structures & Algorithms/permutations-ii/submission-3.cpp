class Solution {

    unordered_map<int,int> nMap;
    vector<vector<int>> res;
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        for(auto n : nums){
            nMap[n]++;
        }

        vector<int> curPerm;

        helper(nums,curPerm);

        return res;

    }


    void helper(const vector<int>& nums, vector<int>& curPerm){

        if(curPerm.size() == nums.size()){
            res.push_back(curPerm);
            return;
        }

        for(auto [num,cnt] : nMap){
            if(cnt > 0){
                curPerm.push_back(num);
                nMap[num]--;
                helper(nums,curPerm);
                curPerm.pop_back();
                nMap[num]++;
            }
        }


    }
};