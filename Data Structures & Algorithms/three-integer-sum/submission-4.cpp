class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // O(nlogn)
        
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i+-1]) continue;
            int L=i+1, R=nums.size()-1;
            while(L<R){

                int sum = nums[i] + nums[L] + nums[R];

                if(sum > 0){
                    R--;
                }else if(sum < 0){
                    L++;
                }else{
                    res.push_back({nums[i],nums[L],nums[R]});
                    L++;
                    while(L<R && nums[L-1] == nums[L]){
                        L++;
                    }
                }
            }
        }
        return res;
        
    }
};
