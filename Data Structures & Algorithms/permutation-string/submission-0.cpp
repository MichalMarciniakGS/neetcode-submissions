class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()){
            return false;
        }
        
        int L = 0;
        int R = s1.size()-1;
        int length = s1.size();
        unordered_map<char,int> unMap;
        unordered_map<char,int> unMapWindow;

        for(const auto& ch : s1){
            unMap[ch]++;
        }

        for(int i=0; i<s1.size(); i++){
            unMapWindow[s2[i]]++;
        }

        while(R < s2.size()){
            // while(L <= R){
            //     unMapWindow[s2[L]]++;
            //     L++;
            // }
            if(unMap == unMapWindow){
                return true;
            }
            unMapWindow[s2[L]]--;
            if(unMapWindow[s2[L]] == 0){
                unMapWindow.erase(s2[L]);
            }
            L++;
            R++;
            if(R < s2.size()){
                unMapWindow[s2[R]]++;
            }

            // R++;
            // unMapWindow[s2[R]]++;
            // unMapWindow[s2[L]]--;
            // L++;
        }

        return false;

    }
};
