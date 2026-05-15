class Solution {

    vector<string> res;
    vector<string> letters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()){
            return {};
        }

        string curComb = "";
        helper(0,digits,curComb);

        return res;
        
    }

    void helper(int i, string digits, string curComb){

        if(digits.size() == curComb.size()){
            res.push_back(curComb);
            return;
        }

        string curChars = letters[digits[i] - '0'];

        for(auto c : curChars){
            // curComb = curComb + c;
            helper(i+1, digits, curComb + c);
        }

    }
};
