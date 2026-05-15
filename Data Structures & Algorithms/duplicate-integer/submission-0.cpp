class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> numbers;

        for(auto num : nums){
            if(numbers.count(num) == 0){
                numbers[num] = 1;
            }
            else{
                return true;
            }
        }
        return false;

    }
};
