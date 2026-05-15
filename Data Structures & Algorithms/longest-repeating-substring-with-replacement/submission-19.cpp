class Solution {
public:
    int characterReplacement(string s, int k) {

        int L = 0 ;
        int res = 0;
        int currMostChar = 0;
        unordered_map<char,int> mostChar;

        for(int R=0; R<s.size(); R++){

            mostChar[s[R]]++;

            currMostChar = max(currMostChar, mostChar[s[R]]);

            while((R-L+1) - currMostChar > k){
            mostChar[s[L]]--;
            L++;

            // for(auto& [ch,i] : mostChar){
            //     currMostChar = max(currMostChar, i);
            // }

            currMostChar = 0;
            for (auto& p : mostChar){
                currMostChar = max(currMostChar, p.second);
            }

            }

            res = max(res, R-L+1);
        }

        return res;
    }
};
