class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // -4,-1-1,0,1,2

        vector<vector<int>> res = {};

        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int L=i+1;
            int R=nums.size()-1;

            int tripleSum = nums[i] + nums[L] + nums[R];
            
            while(L < R){

                if(tripleSum == 0){
                    res.push_back({nums[i],nums[L],nums[R]});
                    L++;
                    while(nums[L] == nums[L-1]){
                        L++;
                    }
                    R--;
                }
                
                if(tripleSum < 0){
                    L++;
                }

                if(tripleSum > 0){
                    R--;
                }
                tripleSum = nums[i] + nums[L] + nums[R];


            }

            // while(tripleSum < 0 && L<R){
            //     L++;
            //     tripleSum = nums[i] + nums[L] + nums[R];
            // }

            // while(tripleSum > 0 && R>L){
            //     R--;
            //     tripleSum = nums[i] + nums[L] + nums[R];
            // }
        }

        return res;
        
    }
};
