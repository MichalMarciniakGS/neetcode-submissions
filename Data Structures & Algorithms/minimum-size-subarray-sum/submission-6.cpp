class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int length = INT_MAX;
        int sum = 0;
        int L = 0;

        for(int R=0; R<nums.size(); R++){

            sum += nums[R]; // 2+1+5+1+5 = 14

            while(sum >= target){
                length = min(length, R-L+1);
                sum -= nums[L]; // 14-2 = 12-1=11 -> 11-5=6
                L++;
            }

        }

        return length == INT_MAX ? 0 : length;

    }
};