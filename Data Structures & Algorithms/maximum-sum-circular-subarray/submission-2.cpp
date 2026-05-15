class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = 0;
        int globalMax = nums[0], globalMin = nums[0];
        int currMax = 0, currMin = 0;


        for(int R=0; R<nums.size(); R++){

            total += nums[R];

            currMax = max(nums[R], currMax+nums[R]);

            currMin = min(nums[R], currMin+nums[R]);

            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);

        }

        return globalMax > 0 ? max(globalMax, total-globalMin) : globalMax;

    }
};