class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mapNums;

        for(auto num: nums){
            if(mapNums.count(num) == 1){
                return true;
            }else{
                mapNums.insert({num,0});
            }
        }
        return false;
    }
};
