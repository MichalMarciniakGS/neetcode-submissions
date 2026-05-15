class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> cache;
        int L=0;
        int length = 0;

        for(int R=0; R<s.size(); R++){

            while(cache.count(s[R])){
                cache.erase(s[L]);
                L++;
            }

            cache.insert(s[R]);
            length = max(length,R-L+1);

        }

        return length;
        
    }
};
