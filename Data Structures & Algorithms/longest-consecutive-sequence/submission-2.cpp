class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numsSet(nums.begin(), nums.end());
        int res = 0;

        for(auto n : nums){

            if(!numsSet.count(n-1)){
                int curRes = 0;
                int curNum = n;
                while(numsSet.count(curNum)){
                    curRes++;
                    res = max(res,curRes);
                    curNum++;
                }

            }

        }

        return res;


        
    }
};
