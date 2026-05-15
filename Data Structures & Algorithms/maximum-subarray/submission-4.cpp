class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int L=0;
        int curSum = 0;
        int maxSum = nums[0];

        for(int R=0; R<nums.size(); R++){

            curSum = max(curSum + nums[R], nums[R]);
            maxSum = max(maxSum, curSum);

        }

        return maxSum;

    }
};
