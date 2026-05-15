class Solution {

    vector<int> visited;

public:
    int rob(vector<int>& nums) {

        visited.assign(nums.size(),-1);
        return helper(0,nums);
        
    }

    int helper(int i, vector<int>& nums){

        if(i >= nums.size()){
            return 0;
        }

        if(visited[i] != -1){
            return visited[i];
        }

        visited[i] = max((nums[i] + helper(i+2,nums)), helper(i+1,nums));

        return visited[i];

    }
};
