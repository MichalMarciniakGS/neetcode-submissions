class Solution {

    vector<vector<int>> cache;

public:
    int coinChange(vector<int>& coins, int amount) {

        cache.assign(coins.size(), vector<int>(amount+1, -1));
        int result = dfs(0,coins,amount);
        return (result >= 1000000) ? -1 : result;
        
    }

    int dfs(int i, vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        if(i >= coins.size() || amount < 0){
            return 1000000;
        }

        if(cache[i][amount] != -1){
            return cache[i][amount];
        }

        //skip res
        int skip = dfs(i+1, coins, amount);

        int newAmount = amount - coins[i];
        int take = 1000000;
        if(newAmount >= 0){
            // for(auto coin : coins){
                take = 1 + dfs(i, coins, newAmount);
            // }
        }

        cache[i][amount] = min(skip,take);
        return cache[i][amount];

    }
};
