class Solution {
public:
    int characterReplacement(string s, int k) {

        int L=0;
        int length = 1;
        int maxFreq=0;
        unordered_map<int,int> cache;

        for(int R=0; R<s.size(); R++){

            cache[s[R]]++;
            maxFreq = max(maxFreq, cache[s[R]]);

            while((R-L+1)-maxFreq > k){
                cache[s[L]]--;
                L++;
            }
            
            length = max(length, R-L+1);

        }

        return length;
        
    }
};
