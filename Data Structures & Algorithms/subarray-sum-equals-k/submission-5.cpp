class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> numsMap;
        numsMap[0]++;

        int res = 0;

        int curSum = 0;
        for(auto num : nums){
            curSum += num;
            int diff = curSum - k;
            res += numsMap[diff];
            numsMap[curSum]++;


        }

        return res;
        
    }
};