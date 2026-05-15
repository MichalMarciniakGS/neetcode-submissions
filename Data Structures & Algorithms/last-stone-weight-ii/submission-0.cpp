class Solution {

    vector<vector<int>> memo;

public:
    int lastStoneWeightII(vector<int>& stones) {

        int stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = stoneSum / 2;

        memo.assign(stones.size(), vector<int>(target+1, -1));

        return dfs(0,0,target, stones, stoneSum);


        
        
    }

    int dfs(int i, int total, int target,const vector<int>& stones, int stoneSum){

        if(total >= target || i >= stones.size()){
            return abs(total - (stoneSum - total));
        }

        if(memo[i][total] != -1){
            return memo[i][total];
        }

        memo[i][total] = min(dfs(i+1,total,target,stones,stoneSum), dfs(i+1, total + stones[i], target, stones,stoneSum));
        return memo[i][total];
    }
};