class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> all(nums.begin(), nums.end());
        int length = 0;

        for(auto num : nums){

            if(!all.count(num-1)){
                int currLength = 0;
                int currNum = num;
                while(all.count(currNum)){
                    currLength++;
                    length = max(length,currLength);
                    currNum++;
                }

            }

        }

        return length;
        
    }
};
