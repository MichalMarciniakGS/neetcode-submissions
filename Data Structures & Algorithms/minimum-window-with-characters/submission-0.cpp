class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> unMapS;
        unordered_map<char,int> unMapT;

        if(t.size() > s.size()){
            return "";
        }

        for(const auto& ch : t){
            unMapT[ch]++;
        }

        // for(const auto& ch : s){
        //     unMapS[ch]++;
        // }

        // for(const auto& [chT,iT] : unMapT){
        //     auto findChIt = unMapS.find(chT);
        //     if(findChIt == unMapS.end()){
        //         return "";
        //     }else if(unMapS[chT] < unMapT[chT]){
        //         return "";
        //     }
        // }

        int L = 0;
        // int R = s.size()-1;
        int R = 0;
        // string outString = "";

        int bestLen = INT_MAX;
        int bestStart = 0;

        // while (L < R || ((R-L-1) != t.size())){
        //     unMapS[L]--;
        //     L++;
        //     if(stillViable(unMapT, unMapS)){
        //         continue;
        //     }else{
        //         L--;
        //         unMapS[L]++;
        //     }
        //     unMapS[R]--;
        //     R--;

        // }

        while(R < s.size()){
            unMapS[s[R]]++;
            // outString = outString + s[R];
            R++;
            if(stillViable(unMapT, unMapS)){
                while(stillViable(unMapT, unMapS)){
                    unMapS[s[L]]--;
                    L++;
                }
                int currLen = R - (L-1);
                if(currLen < bestLen){
                    bestLen = currLen;
                    bestStart = L-1;
                }
            }
        }

        if (bestLen == INT_MAX) return "";
        return s.substr(bestStart,bestLen);

        
    }

    bool stillViable(const unordered_map<char,int>& mapT, const unordered_map<char,int>& mapS){
        // for(const auto& [chT,iT] : mapT){
        //     auto findChIt = mapS.find(chT);
        //     if(findChIt == mapS.end()){
        //         return false;
        //     }else if(mapS[chT] < mapT[chT]){
        //         return false;
        //     }
        // }
        // return true;

        for(const auto& [chT, iT] : mapT){
            auto it = mapS.find(chT);
            if (it == mapS.end()) return false;
            if (it->second < iT) return false;
        }
        return true;
    }
};
