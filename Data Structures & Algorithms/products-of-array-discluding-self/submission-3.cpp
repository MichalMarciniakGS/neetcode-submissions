class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //[1, 2, 4, 6]
        //[48,24,12,8]

        int n = nums.size();
        vector<int> leftSide(n,1);
        //[1,1,2,8]

        vector<int> rightSide(n,1);
        //[48,24,6,1]

        vector<int> res(n,0);

        for(int i=1; i<n; i++){
            leftSide[i] = nums[i-1] * leftSide[i-1]; 
        }

        for(int i=n-2; i>=0; i--){
            rightSide[i] = nums[i+1] * rightSide[i+1];
        }

        for(int i=0; i<n; i++){
            res[i] = leftSide[i] * rightSide[i];
        }

        return res;

    }
};
