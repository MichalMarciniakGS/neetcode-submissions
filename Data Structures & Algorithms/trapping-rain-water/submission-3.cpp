class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.empty()){
            return 0;
        }

        int L=0, R=height.size()-1;
        int Lmax=height[0], Rmax=height[height.size()-1];
        int res = 0;

        while(L<R){
            if (Lmax < Rmax){
                L++;
                Lmax = max(Lmax, height[L]);
                res += Lmax - height[L];
            }else{
                R--;
                Rmax = max(Rmax, height[R]);
                res += Rmax - height[R];
            }
        }
        return res;

    }
};
