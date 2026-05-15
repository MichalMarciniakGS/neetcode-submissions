class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int L=0;
        int currMax = 0;
        int maxSum = nums[0];

        for(int R=0; R<nums.size(); R++){

            currMax = max(currMax + nums[R], nums[R]);
            maxSum = max(maxSum, currMax);

        }

        return maxSum;

    }
};
