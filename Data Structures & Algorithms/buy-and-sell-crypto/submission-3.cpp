class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        int currMin = prices[0];

        for(auto& price : prices){
            res = max(res, price-currMin);
            currMin = min(currMin,price);
        }

        return res;
        
    }
};
