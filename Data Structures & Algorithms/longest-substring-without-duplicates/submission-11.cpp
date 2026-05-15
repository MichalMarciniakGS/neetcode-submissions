class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int L = 0;
        unordered_set<char> unSet;
        int size = 0;

        for(const auto& ch : s){

            while(unSet.count(ch)){
                unSet.erase(s[L]);
                L++;
            }

            if(!unSet.count(ch)){
                unSet.insert(ch);
            }

            size = max(size, (int)unSet.size());

        }

        return size;
        
    }
};
