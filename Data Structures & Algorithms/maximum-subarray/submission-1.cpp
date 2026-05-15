class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curSum = 0;
        int maxSum = nums[0];

        // [5, -3, 5]
        // cS=0 -> cs=5, mS=5
        // cs=5 -> cS=2, mS=5
        // cs=2 -> cS=7, mS=7

        for(auto n : nums){
            curSum = max(curSum, 0);
            curSum += n;
            maxSum = max(maxSum, curSum);
        }

        return maxSum;

    }
};
