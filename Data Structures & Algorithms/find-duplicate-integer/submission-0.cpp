class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> seenNums{};

        for(auto num : nums){
            if(seenNums.count(num)){
                return num;
            }
            seenNums.insert(num);
        }
        
    }
};
