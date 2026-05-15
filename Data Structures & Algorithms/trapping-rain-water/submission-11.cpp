class Solution {
public:
    int trap(vector<int>& height) {

        int L=0;
        int R=height.size()-1;

        int maxHeightL = height[L];
        int maxHeightR = height[R];

        int totalWater = 0;
        int totalArea = 0;

        while(L < R){

            if(maxHeightL < maxHeightR){
                L++;
                maxHeightL = max(maxHeightL,height[L]);
                totalWater = max(maxHeightL - height[L],0);
            }else{
                R--;
                maxHeightR = max(maxHeightR,height[R]);
                totalWater = max(maxHeightR - height[R],0);
            }

            totalArea = max(totalArea+totalWater, totalArea);

        }

        return totalArea;
        
    }
};
