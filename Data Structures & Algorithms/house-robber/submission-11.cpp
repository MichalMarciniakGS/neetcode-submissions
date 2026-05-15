class Solution {
public:
    int rob(vector<int>& nums) {

        int r1=0;
        int r2=0;

        for(auto num : nums){
            int temp = max(r1+num,r2);
            r1=r2;
            r2=temp;
        }

        return r2;
        
    }
};
