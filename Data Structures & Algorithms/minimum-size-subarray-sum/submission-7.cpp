class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int length = INT_MAX;
        int curSum = 0;
        int L = 0;

        for(int R=0; R<nums.size(); R++){

            curSum += nums[R];

            while(curSum >= target){
                length = min((R-L+1),length);
                curSum -= nums[L];
                L++;
            }


        }

        return length == INT_MAX ? 0 : length;
        
        
    }
};