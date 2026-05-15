class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        int minVal = prices[0];

        for(auto& price : prices){
            res = max(res, price-minVal);
            minVal = min(minVal, price);
        }

        return res;
        
    }
};
