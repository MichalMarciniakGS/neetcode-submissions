class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_set<int> numsSet(nums.begin(),nums.end());

        for(int i=1; i<=nums.size() + 1; i++){
            if(!numsSet.count(i)){
                return i;
            }
        }
        return -1;
    }
};