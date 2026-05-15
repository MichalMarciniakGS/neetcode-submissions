class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> candies(ratings.size(), 1);

        // [4,3,5]
        // [1,1,1]

        for(int i=1; i<n; i++){
            if(ratings[i-1] < ratings[i] && candies[i] <= candies[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        // [1,1,2]

        for(int i=n-2; i>=0; i--){
            if(ratings[i+1] < ratings[i] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
        
    }
};