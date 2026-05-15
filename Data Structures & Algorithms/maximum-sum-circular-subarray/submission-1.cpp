class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int globMax=nums[0], globMin=nums[0];
        int curMax=0, curMin=0;
        int curSum = 0;

        // 2,3,-6,3,5
        // cs=2, gMin=2, cm=2, gMax=2
        // cs=5, gMin=2, cm=5, gMax=5
        // 

        for(auto num : nums){

            //A bit wrong approach
            //curSum += num;
            //curMin = min(curSum, num);
            //globMin = min(globMin, curMin);
            //curMax = max(curSum,0);
            //globMax = max(globMax, curMax);
            
            //extend or start fresh approach:
            curMax = max(curMax+num, num);
            curMin = min(curMin+num, num);
            curSum += num;
            globMax = max(globMax, curMax);
            globMin = min(globMin, curMin);

        }

        if(globMax > 0){
            return max(globMax, curSum-globMin);
        }else{
            return globMax;
        }

        globMax = max(globMax, curSum-globMin);
        return globMax;
    }
};