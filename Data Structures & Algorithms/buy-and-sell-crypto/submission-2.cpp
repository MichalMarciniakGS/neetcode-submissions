class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0;
        int minVal = prices[0];

        for(auto price : prices){

            maxProfit = max(maxProfit, price-minVal);
            minVal = min(minVal, price);

        }

        return maxProfit;
        
    }
};
