class Solution {

    unordered_map<int,bool> memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        return dfs(s, wordDict, 0);
        
    }

    bool dfs(string s, vector<string>& wordDict, int i){

        if(i == s.size()){
            memo[i] = true;
            return true;
        }

        if(memo.count(i)){
            return memo[i];
        }

        for(const string& w : wordDict){
            if(i + w.size() <= s.size() && s.substr(i, w.size()) == w){
                if(dfs(s, wordDict, i+w.size())){
                    memo[i] = true;
                    return true;
                }
            }
        }

        memo[i] = false;
        return false;

    }
};
