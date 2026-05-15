class Solution {
public:
    string convert(string s, int numRows) {

        vector<string> allStrings(numRows);

        int row = 0;
        int dir = 1;

        for(char c : s){

            allStrings[row] += c;
            row += dir;

            if(row == 0 || row == numRows-1){
                dir *= -1;
            }

        }

        string res = "";

        for(string currString : allStrings){
            res += currString;
        }

        return res;
        
    }
};