class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int L=0;
        int total = 0;
        int length = INT_MAX;

        for(int R=0; R< nums.size(); R++){

            total += nums[R];

            // if(total >= target){
                while(total >= target){
                length = min(R-L+1, length);
                total -= nums[L];
                L++;
            }

        }

        if(length == INT_MAX){
            return 0;
        }

        return length;
        
    }
};