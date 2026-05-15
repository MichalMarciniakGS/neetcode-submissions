class Solution {

    vector<vector<int>> memo;

public:
    int coinChange(vector<int>& coins, int amount) {

        memo.assign(coins.size(), vector<int>(amount+1, -1));
        int result = dfsHelper(0,coins,amount);
        return (result >= 100000) ? -1 : result;
        
    }

    int dfsHelper(int i, const vector<int>& coins, int amount){

        if(amount == 0){
            return 0; //0 - valid way found, so no more coins needed
        }

        if(amount < 0 || i >= coins.size()){
            return 100000; // large number, impossible case
        }

        if(memo[i][amount] != -1){
            return memo[i][amount];
        }

        //skip
        int currRes = dfsHelper(i+1, coins, amount);

        int newAmount = amount - coins[i];
        if(newAmount >= 0){
            int res = 1 + dfsHelper(i, coins, newAmount);
             currRes = min(res, currRes);
        }

        memo[i][amount] = currRes;
        return currRes;


    }
};
