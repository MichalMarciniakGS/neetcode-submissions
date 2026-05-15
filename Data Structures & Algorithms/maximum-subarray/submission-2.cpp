class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curSum = 0;
        int maxSum = nums[0];

        // [2,-3,5,6]
        // cs=2 ms=2
        // cs=2 -> cs=-1 ms=2
        // cs=0

        for(int R=0; R<nums.size(); R++){

            curSum = max(curSum, 0);
            curSum += nums[R];
            maxSum = max(curSum, maxSum);

        }
        return maxSum;

    }
};
