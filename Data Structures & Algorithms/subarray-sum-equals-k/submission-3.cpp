class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> cache;
        cache[0]++;
        int curSum = 0;
        int res = 0;

        for(int n : nums){
            curSum += n;
            int diff = curSum - k;
            res += cache[diff];
            cache[curSum]++;
        }

        return res;
        
    }
};