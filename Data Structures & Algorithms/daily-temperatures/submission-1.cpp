class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> res = {};

        for(size_t i{0}; i<temperatures.size(); ++i){
            // for(size_t = i+1; i<temperatures.size(); ++i){
            //     if()
            // }
            size_t k = i+1;
            while(k < temperatures.size()){
                if(temperatures[i] < temperatures[k]){
                    res.push_back(k-i);
                    break;
                }
                k++;
            }
            if(k >= temperatures.size()){
                res.push_back(0);
            }
        }

        return res;
        
    }
};
