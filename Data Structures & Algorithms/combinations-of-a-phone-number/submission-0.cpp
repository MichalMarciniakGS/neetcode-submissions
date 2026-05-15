class Solution {

    vector<string> res;
    vector<string> digitToChar = {"","","abc","def","ghi","jkl","mno","qprs","tuv","wxyz"};

public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()){
            return {};
        }

        string curComb = "";
        helper(0,digits,curComb);
        return res;
        
    }

    void helper(int i, const string& digits, string curComb){

        if(curComb.size() == digits.size()){
            res.push_back(curComb);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for(char c: chars){
            helper(i+1, digits, curComb + c);
        }
    }
};
