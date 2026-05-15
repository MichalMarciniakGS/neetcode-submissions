class Solution {
public:
    bool isPalindrome(string s) {
        
        int L=0;
        int R=s.size()-1;

        while (L<R){

            //skip all space/non-alphanumeric chars from left
            while(L < R && !isalnum(s[L])){
                L++;
            }

            //skip all space/non-alphanumeric chars from right
            while(L < R && !isalnum(s[R])){
                R--;
            }

            //get chars to lower before comparing, since we
            // dont care about case-sensitive
            if(tolower(s[L]) != tolower(s[R])){
                return false;
            }
            L++;
            R--;
        }
        return true;

    }
};
