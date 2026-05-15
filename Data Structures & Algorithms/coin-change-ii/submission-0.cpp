// Memoization Solution for Leetcode 518 - Coin Change II
// Problem: Count number of ways to make change for given amount using unlimited coins

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> memo(coins.size()+1, vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end());
        
        return dfs(coins, 0, amount, memo);
    }

    int dfs(const vector<int>& coins, int i, int a, vector<vector<int>>& memo){

        if(a == 0){
            return 1; 
        }

        if(i >= coins.size()){
            return 0; 
        }

        if(memo[i][a] != -1){
            return memo[i][a];
        }

        int res = 0;
        
        if(a >= coins[i]){
            res = dfs(coins, i+1, a, memo) + dfs(coins, i, a-coins[i], memo);
        }
        
        memo[i][a] = res;
        
        return res;
    }
};
