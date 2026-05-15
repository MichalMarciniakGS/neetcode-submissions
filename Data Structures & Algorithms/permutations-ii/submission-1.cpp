class Solution {
    vector<vector<int>> res;
    unordered_map<int,int> count;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        for(auto n : nums){
            count[n]++;
        } 
        vector<int> perm;
        dfs(nums,perm);

        return res;    
        
    }

    void dfs(const vector<int>& nums, vector<int> perm){

        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(auto [num,cnt] : count){
            if(cnt > 0){
                perm.push_back(num);
                count[num]--;
                dfs(nums,perm);

                count[num]++;
                perm.pop_back();
            }
        }

    }
};