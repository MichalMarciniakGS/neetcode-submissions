class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int res = INT_MAX;
        int total = 0;
        int L = 0;

        for(int R=0; R<nums.size(); R++){

            total += nums[R];

            while(total >= target){
                res = min(R-L+1, res);
                total -= nums[L];
                L++;

            }

        }

        return res == INT_MAX ? 0 : res;
        
    }
};