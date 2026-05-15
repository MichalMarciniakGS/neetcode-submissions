class Solution {
public:
    int characterReplacement(string s, int k) {

        // XYYX k=2  -> 4

        unordered_map<char,int> charsM;

        int length = 1;
        int maxFreq = 0;
        int L=0;

        for(int R=0; R<s.size(); R++){

            charsM[s[R]]++;
            maxFreq = max(maxFreq, charsM[s[R]]);

            while((R-L+1) - maxFreq > k){
                charsM[s[L]]--;
                L++;
            }

            length = max(length, (R-L+1));

        } 

        return length;
        
    }
};
