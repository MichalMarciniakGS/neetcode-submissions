class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> numsMap;

        for(int i=0; i<nums.size(); i++){
            numsMap[nums[i]] = i; // [1,3,4] target=7
            // 3->1
            // 4->2
        }

        for(int i=0; i<nums.size(); i++){
            if(numsMap.count(target-nums[i]) && numsMap[target-nums[i]] != i){
                return {i,numsMap[target-nums[i]]};
            }
        }
        return {-1,-1};

    }
};
