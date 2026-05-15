class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int L=0;
        int curSum=0, maxSum=nums[0];
        int curMinSum=0, minSum = nums[0];
        int total=0;

        for(int R=0; R<nums.size(); R++){

            total += nums[R];
            curSum = max(curSum + nums[R], nums[R]);
            curMinSum = min(curMinSum + nums[R], nums[R]);

            minSum = min(curMinSum, minSum);
            maxSum = max(curSum, maxSum);

        }

        return maxSum > 0 ? max(total-minSum,maxSum) : maxSum;

    }
};