class Solution {
public:
    int trap(vector<int>& height) {

        int L=0;
        int R=height.size()-1;

        int Lmax = height[L];
        int Rmax = height[R];

        int res = 0;

        while(L < R){

            if(Lmax < Rmax){
                res += max(Lmax - height[L], 0);
                L++;
                Lmax = max(Lmax, height[L]);
            }else{
                res += max(Rmax - height[R],0);
                R--;
                Rmax = max(Rmax, height[R]);
            }

        }

        return res;
        
    }
};
