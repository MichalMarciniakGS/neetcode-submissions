class Solution {

    vector<int> cache;

public:
    int rob(vector<int>& nums) {

        cache.assign(nums.size(), -1);
        return helper(0,nums);
        
    }

    int helper(int i, const vector<int>& nums){

        if(i >= nums.size()){
            return 0;
        }

        if(cache[i] != -1){
            return cache[i];
        }

        cache[i] = max(helper(i+1,nums), nums[i] + helper(i+2,nums));
        return cache[i];

    }
};
