class Solution {

    unordered_set<int> numSet;

public:
    int longestConsecutive(vector<int>& nums) {

        numSet.insert(nums.begin(),nums.end());
        int longest = 0;

        //We want to check what are the beginnings of the
        //sequences, so we check if num has num-1 (left neigbour)
        //if not, it means it has to be start of sequence
        //at num

        for(auto num : nums){
            //is start of the sequence?
            if(!numSet.count(num-1)){
                int length = 0;
                while(numSet.count(num+length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;

        
    }
};
