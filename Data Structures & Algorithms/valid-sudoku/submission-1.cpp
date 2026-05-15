class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_map<char,int>> colMaps(9);
        vector<unordered_map<char,int>> boxMaps(9);
        // for(const vector<char>& row : board){
        for(int r=0; r<9; r++){
            unordered_map<char,int> unMapR = {};
            for(int c=0; c<9; c++){
                // unordered_map<char,int> unMapR = {};
                if(board[r][c] == '.'){
                    continue;
                }
                if(unMapR.count(board[r][c])){
                    return false;
                }

                if(colMaps[c].count(board[r][c])){
                    return false;
                }

                int boxIndex = (r/3) * 3 + (c/3);

                if(boxMaps[boxIndex].count(board[r][c])){
                    return false;
                }

                // unMapR[board[r][c]]++;
                unMapR.insert({board[r][c],1});

                //colMaps insert
                colMaps[c].insert({board[r][c],1});

                //boxMaps insert
                boxMaps[boxIndex].insert({board[r][c],1});
            }
        }
        return true;
    }
};
