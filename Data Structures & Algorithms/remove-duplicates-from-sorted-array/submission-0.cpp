class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L=1;

        for(int R=1; R<nums.size(); R++){
            if(nums[R] != nums[R-1]){
                nums[L++] = nums[R]; // Dziwne to, do powtórki i przekminy
            }
        }
        return L;
    }
};