class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int uniq = 1;
        int L=1;

        for(int R=1; R<nums.size(); R++){

            if(nums[R-1] != nums[R]){
                nums[L] = nums[R];
                L++;
                uniq++;
            }

        }
        return uniq;


        
    }
};