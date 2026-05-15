class Solution {

    vector<int> memo;

public:
    int coinChange(vector<int>& coins, int amount) {

    memo.assign(amount+1,-1);
    int minCoins = dfs(coins,amount);
    return (minCoins >= 1000000) ? -1 : minCoins;
        
    }

    int dfs(vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        if(memo[amount] != -1){
            return memo[amount];
        }

        int res = 1000000;

        for(int coin : coins){
            if(amount - coin >= 0){
                res = min(res, 1 + dfs(coins, amount-coin));
            }
        }

        memo[amount] = res;
        return memo[amount];

    }
};
