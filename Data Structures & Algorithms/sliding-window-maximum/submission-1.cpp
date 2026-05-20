class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res = {};

        int numOfMoves = nums.size()-k;

        int L = 0;
        int R = k-1;

        while(R < nums.size()){
        int currMax = getCurrWindowMax(L,R,nums);
        L++;
        R++;
        res.push_back(currMax);
        }

        return res;
        
    }

    int getCurrWindowMax(int L, int R, const vector<int>& nums){

        int currMax = nums[L];
        for(int i = L; i <= R; i++){
            if(currMax < nums[i]){
                currMax = nums[i];
            }
        }
        return currMax;
    }
};
