class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()){
            return 0;
        }

        int length = 0;
        int L=0;
        unordered_set<char> allChar;

        for(int R=0; R<s.size(); R++){

            while(allChar.count(s[R])){
                allChar.erase(s[L]);
                L++;
            }

            length = max(length, R-L+1);

            allChar.insert(s[R]);
        }

        return length;

        

    }
};
