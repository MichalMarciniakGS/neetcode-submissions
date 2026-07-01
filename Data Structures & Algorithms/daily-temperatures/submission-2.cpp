class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> res(temperatures.size(),0);

        for(size_t i{0}; i<temperatures.size(); ++i){
          size_t k = i+1;
            while(k < temperatures.size() && temperatures[k] <= temperatures[i]){
                k++;
            }
            if(k < temperatures.size()){
                res[i] = k-i;
            }else{
                res[i] = 0;
            }
        }

        return res;
        
    }
};
