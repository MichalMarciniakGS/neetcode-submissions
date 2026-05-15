class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<bool> visited(strs.size(), false);
        vector<vector<string>> allAns = {};

        for(int i=0; i<strs.size(); i++){
            if(visited[i]) continue;

            unordered_map<char,int> unMap = {};
            vector<string> currAns = {};
            for(auto ch : strs[i]){
                if(unMap.count(ch)){
                    unMap[ch]++;
                }else{
                    unMap.insert({ch,1});
                }
            }
            currAns.push_back(strs[i]);

            for(int j=i+1; j<strs.size(); j++){
                if(visited[j]) continue;

                if(strs[i].size() != strs[j].size()){
                    continue;
                }
                bool isAnagram = true;
                unordered_map<char,int> tempMap = unMap;
                for(auto ch : strs[j]){
                    if(unMap[ch] == 0){
                        isAnagram = false;
                        break;
                    }
                    tempMap[ch]--;
                }

                if(isAnagram){
                    for(auto& p : tempMap){
                        if(p.second != 0){
                            isAnagram = false;
                            break;
                        }
                    }
                }

                if(isAnagram){
                    currAns.push_back(strs[j]);
                    visited[j] = true;
                }

            }
            allAns.push_back(currAns);
        }

        return allAns;
        
    }
};
