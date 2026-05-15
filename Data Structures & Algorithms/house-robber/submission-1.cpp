class Solution {

    unordered_map<int,int> cache;
public:
    int rob(vector<int>& nums) {
        return dfs(nums,0);
    }

    int dfs(vector<int>& nums, int i){
        if(i >= nums.size()){
            return 0;
        }

        if(cache.count(i)){
            return cache[i];
        }

        cache[i] = max(dfs(nums, i+1), nums[i]+dfs(nums, i+2));
        return cache[i];
    }
};
