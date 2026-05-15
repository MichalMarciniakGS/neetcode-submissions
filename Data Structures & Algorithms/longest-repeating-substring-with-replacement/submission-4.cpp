class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int L=0;
        unordered_map<char,int> visited;
        int res=0, maxFreq=0;

        for(int R=0; R<s.size(); R++){

            visited[s[R]]++;

            maxFreq = max(maxFreq, visited[s[R]]);

            while(R-L+1 - maxFreq > k){
                visited[s[L]]--;
                L++;
            }

            res = max(R-L+1, res);
        }

        return res;

    }
};
