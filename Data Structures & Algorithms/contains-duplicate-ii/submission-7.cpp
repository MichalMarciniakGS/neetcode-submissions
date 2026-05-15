class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int L=0;
        unordered_set<int> cache;
        
        for(int R=0; R<nums.size(); R++){

            if((R-L) > k){
                cache.erase(nums[L]);
                L++;
            }

            if(cache.count(nums[R])){
                return true;
            }

            cache.insert(nums[R]);

        }
        return false;
        
    }
};