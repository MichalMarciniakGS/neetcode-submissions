class Solution {
public:
    int maxArea(vector<int>& heights) {

        int L=0, R=heights.size()-1;
        int Lh = heights[L], Rh = heights[R];
        int maxArea = 0;

        while(L < R){

            int minHeight = min(Lh,Rh);
            int area = (R-L) * minHeight;
            maxArea = max(maxArea, area);

            if(Lh < Rh){
                L++;
                Lh = heights[L];
            }else{
                R--;
                Rh = heights[R];
            }

        }

        return maxArea;
        
    }
};
