class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int L=0;
        int curMax=0, curMin=0;
        int globalMax=nums[0], globalMin=nums[0];
        int total = 0;
        
        for(int R=0; R<nums.size(); R++){

            total+=nums[R];

            curMax = max(curMax + nums[R], nums[R]);
            globalMax = max(curMax, globalMax);

            curMin = min(curMin + nums[R], nums[R]);
            globalMin = min(curMin, globalMin);

        }

        return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;
    }
};