class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int curMax =0;
        int curMin = 0;
        
        int globalMax = nums[0];
        int globalMin = nums[0];

        int total = 0;

        for(auto n : nums){
            curMax = max(curMax+n, n);
            curMin = min(curMin+n, n);
            total += n;

            globalMax = max(curMax, globalMax);
            globalMin = min(curMin, globalMin);

        }

        if(globalMax > 0){
            return max(globalMax, total-globalMin);
        }else{
            return globalMax;
        }


    }
};