class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int L = 0;
        int R = s1.size()-1;

        unordered_map<char,int> unMapS1;
        unordered_map<char,int> unMapS2;

        for(const auto& ch : s1){
            unMapS1[ch]++;
        }

        // for(const auto& ch : s2){ ZLE, robie mape dla calego s2 odrazu, bez sensu
        //     unMapS2[ch]++;
        // }

        for(int i=0; i<s1.size(); i++){
            unMapS2[s2[i]]++;
        }

        while(R < s2.size()){

            if(unMapS1 == unMapS2){
                return true;
            }else{
                unMapS2[s2[L]]--;
                if(unMapS2[s2[L]] == 0){
                    unMapS2.erase(s2[L]);
                }
                L++;
            }
            R++;
            unMapS2[s2[R]]++;

        }

        return false;
        
    }

    bool compareMaps(unordered_map<char,int> s1, unordered_map<char,int> s2){
        for(const auto& [ch1, i1] : s1){
            auto currVar = s2.find(ch1);

            if(currVar == s2.end()){
                return false;
            }

            if(currVar != s2.end()){
                if(currVar->second != i1){
                    return false;
                }
            }
        }
        return true;
    }
};
