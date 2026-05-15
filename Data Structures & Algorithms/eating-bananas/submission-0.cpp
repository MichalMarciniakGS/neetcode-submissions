class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());
        int result = R;

        while (L <= R){
            int mid = L + (R-L)/2;
            int totalTime = 0;
            for(double pile : piles){
                totalTime += ceil(pile/mid);
            }

            if(totalTime <= h){
                result = mid;
                R = mid - 1;
            }
            else if(totalTime > h){
                L = mid + 1;
            }
        }
        return result;

    }
};
