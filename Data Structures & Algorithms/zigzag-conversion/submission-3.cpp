class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows >= s.size() || numRows == 1){
            return s;
        }

        vector<string> allStrings(numRows);

        int row=0;
        int dir=1;

        for(char c : s){

            allStrings[row] += c;
            row += dir;

            if(row == 0 || row == numRows-1){
                dir *= -1;
            }

        }

        string res = "";
        for(auto currString : allStrings){
            res += currString;
        }

        return res;
        
    }
};