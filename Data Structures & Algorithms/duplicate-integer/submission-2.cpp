class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> numsMap;

        for(auto num : nums){
        if(numsMap.count(num) == 1){
            return true;
        }
        else{
            numsMap.insert({num,1});
        }
        }
        return false;

    }
};
