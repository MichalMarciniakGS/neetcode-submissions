class Solution {
public:
    int trap(vector<int>& height) {

        int L=0, R=height.size()-1;
        int Lmax=height[L], Rmax=height[R];
        int maxArea = 0;

        while(L < R){

            if(Lmax < Rmax){
                L++;
                Lmax = max(Lmax,height[L]);
                maxArea += max(Lmax - height[L],0);
            }else{
                R--;
                Rmax = max(Rmax,height[R]);
                maxArea += max(Rmax - height[R],0);
            }
            

        }

        return maxArea;
        
    }
};
