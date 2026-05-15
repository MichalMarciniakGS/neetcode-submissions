class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> numMap;

        for(auto num : nums){
            if(numMap.count(num) == 1){
                return true;
            }
            numMap[num] = 1;
        }
        return false;
    }
};
