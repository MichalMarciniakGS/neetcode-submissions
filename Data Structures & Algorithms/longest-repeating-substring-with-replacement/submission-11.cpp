class Solution {
public:
    int characterReplacement(string s, int k) {

        if(s.empty()){
            return 0;
        }

        unordered_map<char, int> allChars;
        int L=0;
        int maxLength = 1;
        int counter = 0;

        for(int R=0; R<s.size(); R++){

            allChars[s[R]]++;
            counter = max(counter, allChars[s[R]]);

            while((R-L+1) - counter > k && L<R){
                allChars[s[L]]--;
                L++;
            }

            if( (R-L+1) - counter <= k){
                maxLength = max(maxLength, R-L+1);
            }

            


        }

        return maxLength;
        
    }
};
