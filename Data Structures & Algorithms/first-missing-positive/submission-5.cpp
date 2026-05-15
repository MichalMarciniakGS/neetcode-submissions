class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // Time O(n) - loop and creating hashSet from vec
        // Space O(n) - additional space for hashSet

        unordered_set<int> numsSet(nums.begin(), nums.end());

        for(int i=1; i<=nums.size(); i++){
            if(numsSet.count(i)){
                continue;
            }else{
                return i;
            }
        }

        return nums.size()+1;

    }
};