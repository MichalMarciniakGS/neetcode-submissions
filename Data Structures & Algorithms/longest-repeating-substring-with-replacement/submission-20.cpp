class Solution {
public:
    int characterReplacement(string s, int k) {

        int L=0;
        int res = 0;
        int currMaxChar = 0;
        unordered_map<char,int> unMap;


        for(int R=0; R<s.size(); R++){

            unMap[s[R]]++;
            for(const auto& [ch,n] : unMap){
                currMaxChar = max(currMaxChar,n);
            }

            while((R-L+1)-currMaxChar > k){
                unMap[s[L]]--;
                L++;
            }


            res = max((R-L+1),res);

        }

        return res;
        
    }
};
