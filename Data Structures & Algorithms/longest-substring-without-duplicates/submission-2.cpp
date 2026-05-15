class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> visited;
        int resLength = 0;
        int curLength = 0;
        int L=0;



        // while(L < s.size()){
            for(int R=0; R<s.size(); R++){
            
            while(visited.count(s[R])){
                visited.erase(s[L]);
                L++;
            }

            visited.insert(s[R]);

            curLength = max(R-L+1, curLength);
            resLength = max(curLength, resLength); 

        }

        return !s.empty() ? resLength : 0;

    }
};
