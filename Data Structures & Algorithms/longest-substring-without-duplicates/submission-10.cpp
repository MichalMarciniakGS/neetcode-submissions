class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> unSet;
        int currLength = 0;
        int maxLength = 0;

        int L = 0;

        for(const auto& ch : s){
            while(unSet.count(ch)){
                // currLength = static_cast<int>(unSet.size());
                unSet.erase(s[L]);
                L++;
                currLength--;
                // unSet.clear();
            }
            
            if(!unSet.count(ch)){
            unSet.insert(ch);
            currLength++;
            }

            maxLength = max(maxLength, currLength);
        }

        return maxLength;
        
    }
};
