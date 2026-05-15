class Solution {
public:
    int maxArea(vector<int>& heights) {

        int L=0;
        int R=heights.size()-1;
        int maxRes = 0;

        while (L < R){

            int dist = R-L;
            int currH = min(heights[L],heights[R]);
            int currRes = dist * currH;

            if(currRes > maxRes){
                maxRes = currRes;
            }

            if(heights[L] <= heights[R]){
                L++;
            }else{
                R--;
            }

        }

        return maxRes;
        
    }
};
