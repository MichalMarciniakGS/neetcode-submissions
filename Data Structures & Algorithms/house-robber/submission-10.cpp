class Solution {

    vector<int> visited;

public:
    int rob(vector<int>& nums) {

        visited.assign(nums.size(),-1);
        return helper(0,nums);
        
    }

    int helper(int r, vector<int>& nums){

        if(r >= nums.size()){
            return 0;
        }

        if(visited[r] != -1){
            return visited[r];
        }

        visited[r] = max(helper(r+1,nums), nums[r] + helper(r+2,nums));
        return visited[r];
    }


};
