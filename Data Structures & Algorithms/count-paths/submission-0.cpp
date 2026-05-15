class Solution {
public:
    int uniquePaths(int m, int n) {
        
        return helper(0,0,m,n);
    }

    int helper(int cR, int cC, int m, int n){
        if(cR >= m || cC >= n){
            return 0;
        }

        if(cR == m-1 && cC == n-1){
            return 1;
        }

        return helper(cR+1,cC,m,n) + helper(cR,cC+1,m,n);
    }
};
