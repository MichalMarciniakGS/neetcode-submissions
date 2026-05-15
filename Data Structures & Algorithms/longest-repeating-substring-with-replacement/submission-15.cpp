class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> unMap;
        int res = 0;
        pair<char,int> mostFreq = {'z',0};
        int L = 0;

        for(int R=0; R<s.size(); R++){

            unMap[s[R]]++;

            if(unMap[s[R]] > mostFreq.second){
                mostFreq = {s[R], unMap[s[R]]};
            }

            while((R-L+1) - mostFreq.second > k){
                unMap[s[L]]--;
                if(s[L] == mostFreq.first){
                    mostFreq = {'z',0};
                    for(auto& [ch,cnt] : unMap){
                        if (cnt > mostFreq.second){
                            mostFreq = {ch, cnt};
                        }
                    }
                }
                L++;
            }

            res = max(res,R-L+1);


            // while(R < s.size() && s[L] == s[R]){
            //     unMap[s[R]]++;
            //     if(unMap[s[R]] > mostFreq.second){
            //         mostFreq = {s[R],unMap[s[R]]};
            //     }
            //     R++;
            // }

            // while(s[L] != s[R] && k > 0 && R < s.size()){
            //     k--;
            //     unMap[s[R]]++;
            //     if(unMap[s[R]] > mostFreq.second){
            //         mostFreq = {s[R],unMap[s[R]]};
            //     }
            //     R++;
            // }

            // res = max(res, R-L);

            // while(L < s.size() && ((R-L) - mostFreq.second) <= k){
            //      if(unMap[s[L]] > mostFreq.second){
            //         mostFreq = {s[L],unMap[s[L]]};
            //     }
            //     unMap[s[L]]--;
            //     L++;
            // }

            // if(s[L] != s[R] && k <= 0){
            //     L = R;
            //     k = initialK;
            // }


        }

        return res;
        
    }
};
