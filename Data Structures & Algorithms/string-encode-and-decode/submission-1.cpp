class Solution {
public:

    string encode(vector<string>& strs) {
        string newString = "";
        for(const auto& str: strs){
            int strSize = str.size();
            string strSizeStr = to_string(strSize);
            newString += strSizeStr + "#" + str;
        }
        return newString;
    }

    vector<string> decode(string s) {
        vector<string> allStr = {};
        for(int i=0; i<s.size(); i++){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            string length = s.substr(i,j-i);
            int lengthInt = stoi(length);
            allStr.push_back(s.substr(j+1,lengthInt));
            i=(j+1+lengthInt)-1;
        }
        return allStr;
    }
};
