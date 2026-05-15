class Solution {
public:
    bool isPalindrome(string s) {

        int L = 0;
        int R = s.size()-1;
        
        while(L < R){

            while(L < R && !std::isalnum(s[L])){
                L++;
            }

            while(R > L && !std::isalnum(s[R])){
                R--;
            }

            if(L < R && std::toupper(s[L]) != std::toupper(s[R])){
                return false;
            }

            L++;
            R--;

        }

        return true;
        
    }
};