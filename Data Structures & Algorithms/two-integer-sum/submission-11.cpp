class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> unMap = {};

        for(int i=0; i<nums.size(); i++){
            int currTarget = target - nums[i];
            if(unMap.find(currTarget) != unMap.end()){
                return {unMap.at(currTarget),i};
            }else{
                unMap.insert({nums[i],i});
            }
        }
        return {0,0};
        
    }
};
