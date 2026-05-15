class Solution {
public:
    int trap(vector<int>& height) {

        int L=0, R=height.size()-1;
        int Lmax=height[0], Rmax=height[height.size()-1];
        int res=0;

        // L=0 h=0->L=1 h=2->R=8 h=2->R=7 h=3->L=2 h=0 Lmax=2-> res+=2 L=3 Lmax=3
        // -> R=6 Rmax=3 -> res+=3-1=2 R=5 Rmax=3 -> res+=3-0=3 R=4 -> res+=3-1=2 R=3
        // while condition broken L=3 R=3 -> return res=9 

        while(L < R){

            if(height[L] < height[R]){
                res += max(Lmax-height[L],0);
                L++;
                Lmax = max(Lmax, height[L]);
            }else{
                res += max(Rmax-height[R], 0);
                R--;
                Rmax = max(Rmax, height[R]);
            }

        }

        return res;
        
    }
};
