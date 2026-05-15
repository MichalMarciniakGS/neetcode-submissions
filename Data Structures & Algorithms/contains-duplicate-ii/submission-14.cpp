class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int L=0;
        unordered_set<int> numsSet;
        numsSet.insert(nums[L]);

        for(int R=1; R<nums.size(); R++){

            if(numsSet.count(nums[R])){
                return true;
            }

            while(R-L >= k){
                numsSet.erase(nums[L]);
                L++;
            }

            numsSet.insert(nums[R]);

        }

        return false;


        
    }
};