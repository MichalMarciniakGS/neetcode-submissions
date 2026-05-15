class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> cache;
        int L=0;

        for(int R=0; R<nums.size(); R++){

            while(R-L > k){
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