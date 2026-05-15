class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> curr;
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);

        helper(nums, curr, visited, res);

        return res;
        
    }

    void helper(const vector<int>& nums, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& res){

        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){

            if(visited[i] == true){
                continue;
            }

            curr.push_back(nums[i]);
            visited[i] = true;

            helper(nums,curr,visited,res);

            curr.pop_back();
            visited[i] = false;

        }

    }
};
