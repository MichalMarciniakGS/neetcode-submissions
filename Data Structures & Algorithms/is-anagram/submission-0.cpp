class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> unoMap = {};
        unordered_map<char,int> unoMap2 = {};

        if(s.size() != t.size()){
            return false;
        }


        for(int i=0; i<s.size(); i++){
            // test1.push_back({s[i],i});
            if(unoMap.count(s[i])){
                unoMap[s[i]]++;
            }else{
                unoMap.insert({s[i],1});
            }
        }

        for(int i=0; i<t.size(); i++){
            // test1.push_back({s[i],i});
            if(unoMap2.count(t[i])){
                unoMap2[t[i]]++;
            }else{
                unoMap2.insert({t[i],1});
            }
        }

        if(unoMap == unoMap2){
            return true;
        }else{
            return false;
        }

        
    }
};
