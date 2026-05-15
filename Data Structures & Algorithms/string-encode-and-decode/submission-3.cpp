class Solution {
public:

    string encode(vector<string>& strs) {
        string resStr = "";
        for(const auto& str : strs){
            int strLen = str.size();
            string strLenStr = to_string(strLen);
            resStr += strLenStr + "#" + str;
        }
        return resStr;

        //5#Hello5#World

    }

    vector<string> decode(string s) {
        vector<string> allStr = {};

        int i=0;

        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            // char wordLength = s[i];
            // int wordLengthInt = wordLength - '0';
            string wordLength = s.substr(i,j);
            int wordLengthInt = stoi(wordLength);
            string currWord = s.substr(j+1,wordLengthInt);
            allStr.push_back(currWord);
            i = wordLengthInt+j+1;
        }

        return allStr;
    }
};
