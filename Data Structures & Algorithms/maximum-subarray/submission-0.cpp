class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curSum = 0;
        int maxSum = nums[0];

        // [2,-3,4,-2,1]

        // cS=0 mS=2
        // cS =-1 mS=2
        // cS=0
        // cS=4 mS=4
        // cS=4
        // cS=2 mS=4
        // cS = 2
        // cS = 3 mS=4

        for(auto n : nums){

            curSum = max(curSum,0);
            curSum += n;
            maxSum = max(maxSum, curSum);

        }

        return maxSum;

    }
};
