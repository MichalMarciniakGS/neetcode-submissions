class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st = {};
        vector<int> res(temperatures.size(), 0);

        for(int i{0}; i<temperatures.size(); i++){
            
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int k = st.top();
                st.pop();
                res[k] = i-k;
            }
            st.push(i);
        }

        return res;
        
    }
};
