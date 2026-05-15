class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curMax = 0;
        int globalMax = nums[0];

        for(int R=0; R<nums.size(); R++){

            curMax = max(curMax + nums[R], nums[R]);
            globalMax = max(curMax, globalMax);

        }

        return globalMax;

    }
};
