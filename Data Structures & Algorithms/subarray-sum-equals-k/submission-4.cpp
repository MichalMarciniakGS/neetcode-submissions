class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int total = 0;
        int res = 0;
        unordered_map<int,int> unM;
        unM[0]++;

        for(auto n : nums){
        total += n;
        int diff = total - k;
        res += unM[diff];
        unM[total]++;

        }

        return res;
        
    }
};