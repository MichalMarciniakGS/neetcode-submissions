class Solution {
public:
    int characterReplacement(string s, int k) {

        int L=0;
        int length = 1;
        int curMaxFreq = 0;
        unordered_map<char,int> maxFreq;

        for(int R=0; R<s.size(); R++){

            maxFreq[s[R]]++;
            curMaxFreq = max(curMaxFreq, maxFreq[s[R]]);

            if((R-L+1) - curMaxFreq <= k){
                length = max(length, R-L+1);
            }else{
                maxFreq[s[L]]--;
                L++;
            }


        }

        return length;
        
    }
};
