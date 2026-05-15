class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int nS = nums.size();

        vector<int> leftSide(nS, 1);
        vector<int> rightSide(nS,1);
        vector<int> res(nS,0);

       //nums - 1,2,4,6
        // rS- 48,24,6,1
        // lS - 1,1,2,8
        // re - 48,24,12,8


        for(int i=1; i<nS; i++){
            leftSide[i] = leftSide[i-1] * nums[i-1];
        }

        for(int i=nS-2; i>=0; i--){
            rightSide[i] = rightSide[i+1] * nums[i+1];
        }

        for(int i=0; i<nS; i++){
            res[i] = leftSide[i] * rightSide[i];
        }

        return res;

    }
};
