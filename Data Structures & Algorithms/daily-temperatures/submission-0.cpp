class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> result(temperatures.size(), 0);

        stack<int> baseStack = {};

        for(size_t i{}; i < temperatures.size(); ++i){

            while(!baseStack.empty() && temperatures[i] > temperatures[baseStack.top()]){
                int prevDay = baseStack.top();
                baseStack.pop();
                result[prevDay] = i - prevDay;
            }
            baseStack.push(i);
        }

        return result;

        
    }
};
