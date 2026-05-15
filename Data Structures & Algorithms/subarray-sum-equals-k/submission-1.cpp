class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Example1:
        // nums=[2,-1,1,2]
        // k=2

        //Example2:
        // nums=[4,4,4,4,4,4]
        // k=6

        int res = 0;
        int curSum = 0;

        unordered_map<int,int> prefixSums;
        prefixSums[0]++;

        for(auto n : nums){
            curSum += n;
            int diff = curSum-k;
            res += prefixSums[diff];
            prefixSums[curSum]++;
        }

        return res;

    }
};