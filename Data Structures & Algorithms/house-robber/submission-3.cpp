class Solution {
public:
    int rob(vector<int>& nums) {
        
        int rob1 = 0;
        int rob2 = 0;

        // [r1,r2,4,3,2,5];

        for(auto num : nums){
            int temp = max(rob1 + num, rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;

    }
};
