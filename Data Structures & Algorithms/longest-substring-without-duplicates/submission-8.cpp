class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty()){
            return 0;
        }

        int L=0;
        int length = 0;
        unordered_set<char> visited;

        for(int R=0; R<s.size(); R++){

            while(visited.count(s[R])){
                visited.erase(s[L]);
                L++;
            }

            length = max(length, R-L+1);

            visited.insert(s[R]);

        }

        return length;
        
    }
};
