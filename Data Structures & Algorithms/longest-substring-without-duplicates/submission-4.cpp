class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int length = 0;
        int L=0, R=0;
        unordered_set<char> visited;

        for(auto ch : s){

            while(visited.count(ch)){
                visited.erase(s[L]);
                L++;
            }

            length = max(length, R-L+1);
            visited.insert(ch);
            R++;

        }
        return length;
        
    }
};
