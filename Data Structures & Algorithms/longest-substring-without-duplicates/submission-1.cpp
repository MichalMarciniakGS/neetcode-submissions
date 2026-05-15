class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int L=0;
        unordered_set<char> visited;
        int length = 0;


        for(int R=0; R<s.size(); R++){

            while(visited.count(s[R])){
                visited.erase(s[L]);
                L++;
            }

            visited.insert(s[R]);
            length = max(length, R-L+1);

            // if(!visited.count(s[R])){
            //     visited.insert(s[R]);
            //     length = max(length, R-L+1);
            // }else{
            //     //while()
            //     while(visited.count(s[R])){
            //         visited.erase(s[L]);
            //         L++;
            //     }
                
            }

        return length;

        }
};
