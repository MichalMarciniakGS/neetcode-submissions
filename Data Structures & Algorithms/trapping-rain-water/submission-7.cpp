class Solution {
public:
    int trap(vector<int>& height) {

        int L=0, R=height.size()-1;
        int Lhmax=height[L], Rhmax=height[R];
        int maxArea = 0;

        while(L < R){

            if(Lhmax < Rhmax){
                L++;
                Lhmax = max(Lhmax,height[L]);
                maxArea += Lhmax - height[L];
            }else{
                R--;
                Rhmax = max(Rhmax, height[R]);
                maxArea += Rhmax - height[R];
            }

        }

        return maxArea;
        
    }
};
