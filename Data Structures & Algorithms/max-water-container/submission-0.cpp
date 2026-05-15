class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int R=heights.size()-1, L=0;
        int smallerHeight = 0;
        int res = 0;

        while(L < R){

            smallerHeight = min(heights[L],heights[R]);
            res = max(res, smallerHeight*(R-L));

            if(heights[L] > heights[R]){
                R--;
            }else if(heights[L] < heights[R]){
                L++;
            }else{
                L++;
            }

        }
        return res;

    }
};
