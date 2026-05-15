class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> unMapT;
        unordered_map<char,int> unMapS;

        for(const auto& ch : t){
            unMapT[ch]++;
        }

        int L = 0;
        int R = 0;

        int bestStart = 0;
        int bestLen = INT_MAX;

        int need = unMapT.size();
        int currentNeeded = 0;

        while (R < s.size()){

            unMapS[s[R]]++;

            // while(currentNeeded < need){
                // check if unMapS covers what we have in unMapT
                if(unMapT.count(s[R]) && unMapT[s[R]] == unMapS[s[R]]){
                 currentNeeded++;
                }
            // }
            // bestLast = R;
            // R++;

            while (currentNeeded == need && L <= R){
                int currLen = R-L+1;
                if(currLen < bestLen){
                    bestLen = currLen;
                    bestStart = L;
                }

                if(unMapT.count(s[L]) && unMapT[s[L]] == unMapS[s[L]]){
                    currentNeeded--;
                }
                unMapS[s[L]]--;
                L++;

            }


            // while(currentNeeded >= need){
            //     if(unMapT.count(s[L]) && unMapT[s[L]] == unMapS[s[L]]){
            //         currentNeeded--;
            //     }
            //     unMapS[s[L]]--;
            //     L++;
            //     bestStart++;
            // }

            R++;
        }

        if(bestLen != INT_MAX){
            return s.substr(bestStart, bestLen);
        }else{
            return "";
        }
        
    }
};
