class Solution {

    vector<vector<int>> cache;

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int i = 0;
        int j = 0;
        cache.assign(text1.size(), vector<int>(text2.size(),-1));

        return helper(i,j, text1, text2);
    }

    int helper(int i, int j, const string& text1, const string& text2){
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(cache[i][j] != -1){
            return cache[i][j];
        }

        if(text1[i] == text2[j]){
            cache[i][j] = 1 + helper(i+1, j+1, text1, text2);
        }else{
            cache[i][j] = max(helper(i+1,j,text1,text2), helper(i,j+1,text1,text2));
        }

        return cache[i][j];
    }
};
