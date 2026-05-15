class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> allRes;

        for(const auto& str : strs){
            vector<int> cnt(26,0);
            for(auto ch : str){
                cnt[ch - 'a']++;
            }
            string key = to_string(cnt[0]);
            for (int i=1; i<26; i++){
                key += ',' + to_string(cnt[i]);
            }
            allRes[key].push_back(str);
        }

        vector<vector<string>> finalRes = {};

        for(auto combo : allRes){
            finalRes.push_back(combo.second);
        }

        return finalRes;

    }
};
