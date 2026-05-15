class Solution {
public:
    string longestPalindrome(string s) {

        string res = "";
        int currLen = 0;

        //Case when odd length
        for(int i=0; i<s.size(); i++){
            int l=i;
            int r=i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if((r-l+1) >= currLen){
                    res = s.substr(l, r-l+1);
                    currLen = r-l+1;
                }
                l--;
                r++;
            }
        }

        for(int i=0; i<s.size(); i++){
            int l=i;
            int r=i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if((r-l+1) > currLen){
                    res = s.substr(l, r-l+1);
                    currLen = r-l+1;
                }
                l--;
                r++;
            }
        }

        return res;
        
    }
};
