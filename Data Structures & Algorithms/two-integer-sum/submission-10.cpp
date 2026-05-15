class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> numsMap;

        for(int i=0; i <nums.size(); i++){
            numsMap[nums[i]] = i;
        }

        // 1,3,4 t=7 nums.size() == 3
        // UM => 1->0; 3->1; 4->2

        // 5,5 t=10 nums.size() == 2
        //UM => 5->1

        for(int i=0; i<nums.size(); i++){
            
            auto it = numsMap.find(target-nums[i]);

            if(numsMap.count(target-nums[i]) && target - nums[i]- it->first == 0 
            && i != numsMap[target-nums[i]]){
                return {i, numsMap[target-nums[i]]};
            }
        }

        return {-1,-1};

    }
};
