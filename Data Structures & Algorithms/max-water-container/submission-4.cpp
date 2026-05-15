class Solution {
public:
    int maxArea(vector<int>& heights) {

        int L=0, R=heights.size()-1;
        int maxArea = 0;

        while(L<R){
            
            int minH = min(heights[L],heights[R]);
            maxArea = max(maxArea, minH*(R-L));
            
            if(heights[L] < heights[R]){
                L++;
            }else{
                R--;
            }
        }
        return maxArea;
        
    }
};
