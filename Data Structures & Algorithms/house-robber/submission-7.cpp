class Solution {

    unordered_map<int,int> cache;

public:
    int rob(vector<int>& nums) {

        return helper(0,nums);
        
    }

    int helper(int n, vector<int>& nums){

        if(n >= nums.size()){
            return 0;
        }

        if(cache.count(n)){
            return cache[n];
        }

        cache[n] = max(helper(n+1,nums), nums[n] + helper(n+2,nums));
        return cache[n];

    }
};
