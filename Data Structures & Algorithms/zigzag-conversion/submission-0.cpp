class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> res(numRows);
        int row = 0, dir = 1;

        for (char& c : s) {
            res[row] += c;
            row += dir;
            if (row == 0 || row == numRows - 1) {
                dir *= -1;
            }
        }

        string result;
        for (string& rowString : res) {
            result += rowString;
        }
        return result;
    }
};