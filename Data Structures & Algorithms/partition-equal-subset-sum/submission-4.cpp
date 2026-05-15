class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }

        unordered_set<int> dp;
        dp.insert(0);

        int target = sum/2;

        for(int i=nums.size()-1; i >= 0; i--){

            unordered_set<int> nextDP;

            for(auto t : dp){
                // dp.insert(t+nums[i]);
                nextDP.insert(t+nums[i]);
                nextDP.insert(t);
            }
            dp = nextDP;

        }
        if(dp.count(target)){
            return true;
        }
        return false;
        
    }
};
