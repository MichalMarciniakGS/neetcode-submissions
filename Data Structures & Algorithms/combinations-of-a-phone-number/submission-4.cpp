class Solution {

    vector<string> res;
    vector<string> allLetters = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

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

        if(i == digits.size()){
            res.push_back(curComb);
            return;
        }

        // digits[0] - 3 -> "def";

        string curLetters = allLetters[digits[i] - '0'];

        for(auto c : curLetters){
            helper(i+1,digits, curComb+c);
        }


    }


};
