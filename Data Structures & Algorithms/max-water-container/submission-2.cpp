class Solution {
public:
    int maxArea(vector<int>& heights) {

        int L=0;
        int R=heights.size()-1;

        int Lmax=heights[L];
        int Rmax = heights[R];

        int res = 0;

        while(L < R){

            int minHeight = min(heights[L], heights[R]);
            res = max(res, (R-L) * minHeight);

            if(heights[L] < heights[R]){
                L++;
            }else{
                R--;
            }

        }

        return res;
        
    }
};
