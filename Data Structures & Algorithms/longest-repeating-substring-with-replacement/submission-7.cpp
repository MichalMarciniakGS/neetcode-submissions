class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> charsNums;
        int L = 0;
        int resLength = 0;
        int maxFreq = 0;

        for(int R=0; R<s.size(); R++){
            charsNums[s[R]]++;
            maxFreq = max(maxFreq, charsNums[s[R]]);

            if((R-L+1) - maxFreq <= k){
                resLength = max(resLength, R-L+1);
            }else{
                charsNums[s[L]]--;
                L++;   
            }



        }
        return resLength;

        
    }
};
