class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // O(nlog)
        vector<vector<int>> res;

        for(int i=0; i<nums.size(); i++){

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int L=i+1, R=nums.size()-1;
            while(L<R){

                int threeSum = nums[i]+nums[L]+nums[R];
                if(threeSum > 0){
                    R--;
                }else if(threeSum < 0){
                    L++;
                }else{
                    res.push_back({nums[i],nums[L],nums[R]});
                    L++;
                    while(nums[L] == nums[L-1] && L<R){
                        L++;
                    }
                }

            }

        }
        return res;
        
    }
};
