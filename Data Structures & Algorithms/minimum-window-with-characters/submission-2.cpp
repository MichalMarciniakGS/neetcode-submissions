class Solution {
public:
    string minWindow(string s, string t) {

        // int need = t.size(); Wrong - it should be unique t chars only
        int have = 0;

        int start = 0;
        int bestLen = INT_MAX;

        int L = 0;
        int R = 0;

        unordered_map<char,int> unMapT;
        unordered_map<char,int> unMapS;

        for(const auto& ch : t){
            unMapT[ch]++;
        }

        int need = unMapT.size();

        while(R < s.size()){
            
            unMapS[s[R]]++;
            if(unMapT.count(s[R]) && unMapT[s[R]] == unMapS[s[R]]){
                have++;
            }

            while(have == need && L <= R){
                int currLen = (R-L)+1;
                if(currLen < bestLen){
                    bestLen = currLen;
                    start = L;
                }
                
                unMapS[s[L]]--;
                if(unMapT.count(s[L]) && unMapT[s[L]] > unMapS[s[L]]){
                    have--;
                    // unMapS[s[L]]--; Wrong - misleading for the prev condition
                    // L++; Wrong - block L movement if specific cond is not met  
                }
                L++;

            }

            R++;

        }

        return bestLen == INT_MAX ? "" : s.substr(start,bestLen);
        
    }
};
