class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> visited;
        int L=0;

        for(int R=0; R<nums.size(); R++){

            while(R-L > k){
                visited.erase(nums[L]);
                L++;
            }

            if(visited.count(nums[R])){
                return true;
            }
            
            visited.insert(nums[R]);

        }

        return false;

    }
};