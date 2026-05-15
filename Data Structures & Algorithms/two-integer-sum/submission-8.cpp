class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // [1,3,4]  target = 7  exp: [1,2]
        // [5,5] target = 10 exp: [0,1]

        unordered_map<int,int> numsMap;

        for(int i=0; i<nums.size(); i++){
            numsMap[nums[i]] = i;   // 1->0, 3->1, 4->2
            // 5->1 size=1
        }

        for(int i=0; i<numsMap.size(); i++){
            int diff = target-nums[i];
            if(numsMap.count(diff) && numsMap[diff] != i){
                return {i,numsMap[diff]};
            }
        }
        
    }
};
