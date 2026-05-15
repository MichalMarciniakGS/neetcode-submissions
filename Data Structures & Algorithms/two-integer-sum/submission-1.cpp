class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> numbers;

        for(int i = 0; i < nums.size(); i++){
            numbers[nums[i]] = i;
        }

        

        for(int j = 0; j < nums.size(); j++){
            if(numbers.count(target-nums[j]) > 0 && numbers[target-nums[j]] != j){

                return {j, numbers[target-nums[j]]};
            }    
        }
        return {};

    }
};
