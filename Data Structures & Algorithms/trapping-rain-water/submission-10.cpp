class Solution {
public:
    int trap(vector<int>& height) {

        int L=0;
        int R=height.size()-1;

        int areaMax = 0;
        int currArea = 0;

        int currHighestL = height[L];
        int currHighestR = height[R];

        int totalWater = 0;

        while(L < R){

            if(height[L] < height[R]){
                totalWater += max(currHighestL - height[L], 0);
                currArea = max(totalWater,currArea);    
                L++;
                if(currHighestL < height[L]){
                    currHighestL = height[L];
                }
                // currArea = max(,0)
            }else{
                totalWater += max(currHighestR - height[R], 0);
                currArea = max(totalWater,currArea);
                R--;
                if(currHighestR < height[R]){
                    currHighestR = height[R];
                }
            }

            if(currArea > areaMax){
                areaMax = currArea;
            }

        }

        return areaMax;
        
    }
};
