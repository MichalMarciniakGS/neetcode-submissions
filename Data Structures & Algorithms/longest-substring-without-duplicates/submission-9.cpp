class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()){
            return 0;
        }

        int L=0;
        int length = 1;
        unordered_set<char> allChars;

        for(int R=0; R<s.size(); R++){

            while(allChars.count(s[R])){
                allChars.erase(s[L]);
                L++;
            }

            allChars.insert(s[R]);

            length = max(length, R-L+1);


        }

        return length;
        
    }
};
