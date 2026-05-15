class Solution {
    vector<int> cache;
public:
    int rob(vector<int>& nums) {

        cache.resize(nums.size(), -1);
        return helper(0, nums);
        
    }

    int helper(int n, vector<int>& nums){

        if(n >= nums.size()){
            return 0;
        }
        if(cache[n] != -1){
            return cache[n];
        }

        cache[n] = max(helper(n+1,nums), nums[n] + helper(n+2,nums));
        return cache[n];

    }
};
