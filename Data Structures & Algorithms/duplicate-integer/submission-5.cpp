class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int> test = {};

        for(int i=0; i<nums.size(); i++){
            if(test.count(nums[i])){
                return true;
            }else{
                test.insert(nums[i]);
            }
        }
        return false;
        
    }
};