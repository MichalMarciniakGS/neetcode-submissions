class Solution {
public:
    int rob(vector<int>& nums) {
        
        int rob1=0, rob2=0;
        int temp = 0;

        //t=   1 3 3 4
        //    [1,3,2,1]
        // r1->1->3->3  
        // r2->1->3->3->4

        for(auto n : nums){
            temp = max(rob1+n, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;

    }
};
