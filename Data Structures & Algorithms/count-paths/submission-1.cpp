class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> cache(m, vector<int>(n,0));
        return helper(0,0,cache,m,n);
    }

    int helper(int cR, int cC, vector<vector<int>>& cache, int m, int n){
        if(cR >= m || cC >= n){
            return 0;
        }

        if(cache[cR][cC] > 0){
            return cache[cR][cC];
        }

        if(cR == m-1 && cC == n-1){
            return 1;
        }

        cache[cR][cC] = helper(cR+1,cC,cache,m,n) + helper(cR,cC+1,cache,m,n);
        return cache[cR][cC];
    }
};
