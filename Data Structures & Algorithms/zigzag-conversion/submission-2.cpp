class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size()){
            return s;
        }

        vector<string> rowStrings(numRows);
        int currRow = 0;
        int direction = 1;

        for(auto c : s){
            rowStrings[currRow] += c;
            currRow += direction;

            if(currRow == 0 || currRow == numRows-1){
                direction *= -1;
            }

        }

        string result = "";

        for(string currRow : rowStrings){
            result += currRow;
        }

        return result;
        
    }
};