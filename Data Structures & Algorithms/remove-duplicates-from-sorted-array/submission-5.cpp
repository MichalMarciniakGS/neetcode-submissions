class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int L=1;

        for(int R=1; R<nums.size(); R++){

            // [1,1,2,3,4]

            // [1,2,3,4,4]

             if(nums[R] != nums[R-1]){
                nums[L] = nums[R];
                L++;
             }

        }
        return L;
        
    }
};