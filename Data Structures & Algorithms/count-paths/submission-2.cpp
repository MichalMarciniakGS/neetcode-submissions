class Solution {

    vector<vector<int>> cache;

public:
    int uniquePaths(int m, int n) {
        
        int cr = 0;
        int cc = 0;

        cache.assign(m, vector<int>(n, 0));

        return helper(cr, cc, m, n);

    }

    int helper(int cr, int cc, int m, int n){

        if(cr >= m || cc >= n){
            return 0;
        }

        if(cache[cr][cc] > 0){
            return cache[cr][cc];
        }

        if(cr == m-1 && cc == n-1){
            return 1;
        }

        cache[cr][cc] = helper(cr+1, cc, m, n) + helper(cr, cc+1, m, n);

        return cache[cr][cc];

    }
};
