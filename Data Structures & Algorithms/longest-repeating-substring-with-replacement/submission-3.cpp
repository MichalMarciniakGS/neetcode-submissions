class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> visited;
        int length = 0;
        int L=0;
        int maxFreq = 0;

        for(int R=0; R<s.size(); R++){

            visited[s[R]]++;
            maxFreq = max(maxFreq, visited[s[R]]);
            if((R-L+1) - maxFreq > k){
                visited[s[L]]--;
                L++;
            }
            length = max(R-L+1, length);
        }

        return length;
        
    }
};
