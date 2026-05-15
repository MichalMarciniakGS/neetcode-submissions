class Solution {

    vector<vector<int>> grid;

public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int i=0;
        int j=0;

        grid.assign(text1.size(), vector<int>(text2.size(), -1));

        return helper(i,j,text1,text2);

    }

    int helper(int i, int j, string text1, string text2){

        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(grid[i][j] != -1){
            return grid[i][j];
        }

        if(text1[i] == text2[j]){
            grid[i][j] = 1 + helper(i+1,j+1,text1,text2);
        }else{
            grid[i][j] = max(helper(i+1,j,text1,text2), helper(i,j+1,text1,text2));
        }

        return grid[i][j];
    }
};
