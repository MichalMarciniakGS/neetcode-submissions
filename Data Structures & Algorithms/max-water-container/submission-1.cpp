class Solution {
public:
    int maxArea(vector<int>& heights) {

        int L = 0;
        int R= heights.size()-1;
        int res = 0;
        int minHeight = INT_MAX;

        while(L < R){

            minHeight = min(heights[L],heights[R]);
            res = max(minHeight * (R-L), res);

            if(heights[L] < heights[R]){
                L++;
            }else{
                R--;
            }
        }

        return res;
        
    }
};
