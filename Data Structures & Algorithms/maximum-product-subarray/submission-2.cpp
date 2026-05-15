class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProd = nums[0];
        int minProd = nums[0];

        int globalMax = nums[0];

        int curProd = 1;

        for(int i=1; i<nums.size(); i++){
            int num = nums[i];

            int curMaxProd = num * maxProd;
            int curMinProd = num * minProd;

            maxProd = max({curMinProd, curMaxProd, num});
            minProd = min({curMinProd, curMaxProd, num});

            globalMax = max(maxProd,globalMax);

        }

        return globalMax;

    }
};
