class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1){
            return s;
        }

        string res = "";

        for(int R=0; R<numRows; R++){
            int increment = 2 * (numRows-1);
            for(int i=R; i<s.size(); i += increment){
                res += s[i];
                if(R>0 && R<numRows-1 && i + increment - 2*R < s.size()){
                    res += s[i + increment - 2*R];
                }
            }
        }

        return res;
        
    }
};