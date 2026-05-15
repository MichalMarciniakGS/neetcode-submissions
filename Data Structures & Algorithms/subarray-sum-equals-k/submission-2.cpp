class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int res=0;
        int curSum=0;
        unordered_map<int,int> prefixSums;
        prefixSums[0]++;

        //case nums=[2,-1,1,2] k=2

        for(auto n : nums){
            curSum+=n; // 2 -> 2-1=1 -> 1+1=2 -> 2+2=4
            int diff = curSum-k; // 2-2=0 -> 1-2=-1 -> 2-2=0 -> 4-2=2
            res += prefixSums[diff]; // 0+1 -> 1+0 -> 1+1=2 -> 2+2=4
            prefixSums[curSum]++; // pS[2]=1 -> pS[-1]=1 -> pS[2]=2 -> ps[4]=1
        }
        return res; //res = 4
        
    }
};