class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> visited;
        int result = 0, maxFrequency=0;
        int L=0;

        for(int R=0; R<s.size(); R++){

            visited[s[R]]++;
            maxFrequency = max(maxFrequency, visited[s[R]]);

            while((R-L+1) - maxFrequency > k){
                visited[s[L]]--;
                L++;
            }

            result = max(result, R-L+1);


        }

        return result;

    }
};
