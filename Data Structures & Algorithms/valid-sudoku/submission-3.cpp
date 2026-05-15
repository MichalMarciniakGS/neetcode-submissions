class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> unSetsC(9);
        vector<unordered_set<char>> unSetsBox(9);

        for(int r=0; r<9; r++){
            unordered_set<char> unSetR = {};
            for(int c=0; c<9; c++){

                auto currEl = board[r][c];

                //0-8
                int currBox =  (r/3) * 3 + (c/3);

                //If no element, skip
                if(currEl == '.'){
                    continue;
                }

                //Box check
                if(unSetsBox[currBox].count(currEl)){
                    return false;
                }

                //Col check
                if(unSetsC[c].count(currEl)){
                    return false;
                }

                //Row check
                if(unSetR.count(currEl)){
                    return false;
                }

                //Box add
                unSetsBox[currBox].insert({currEl});

                //Col add
                unSetsC[c].insert({currEl});

                //Row add
                unSetR.insert({currEl});


            }
        }
        return true;
        
    }
};
