class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_map<char,int>> colMaps(9);
        vector<unordered_map<char,int>> boxMaps(9);
        // for(const vector<char>& row : board){
        for(int r=0; r<9; r++){ //each row
            unordered_map<char,int> unMapR = {};
            for(int c=0; c<9; c++){ //each column
                
                //skip if '.', since "A board does not need to be full or be solvable to be valid."
                if(board[r][c] == '.'){
                    continue;
                }

                //check for row
                if(unMapR.count(board[r][c])){
                    return false;
                }

                //check for column
                if(colMaps[c].count(board[r][c])){
                    return false;
                }

                //obtain index of the current box
                int boxIndex = (r/3) * 3 + (c/3);

                //check for current box
                if(boxMaps[boxIndex].count(board[r][c])){
                    return false;
                }

                //unMapR insert
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
