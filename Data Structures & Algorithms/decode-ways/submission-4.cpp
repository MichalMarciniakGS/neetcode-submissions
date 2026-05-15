class Solution {

    vector<int> memo;

public:
    int numDecodings(string s) {

        memo.assign(s.size(), -1);
        return dfs(0,s);
        
    }

    int dfs(int i, string s){

        int res = 0;
        int secRes = 0;

        if(i >= s.size()){
            return 1;
        }

        if(memo[i] != -1){
            return memo[i];
        }

        if(s[i] == '0'){
            return 0;
        }

        res = dfs(i+1,s);

        if(i+1 < s.size() && ((s[i] == '1') || (s[i] == '2') && (s[i+1] <= '6'))){
            secRes = dfs(i+2,s);
        }

        memo[i] = res + secRes;
        return memo[i];


    }
};
