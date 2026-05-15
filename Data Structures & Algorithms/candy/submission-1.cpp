class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> arr(n,1);
        int sum = n;

        // [2,3,5,6,3,3]
        // [1,2,3,4,1,1]

        for(int i=1; i<n; i++){

            if(ratings[i] > ratings[i-1] && arr[i] <= arr[i-1]){
                arr[i] = arr[i-1]+1;
                sum++;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && arr[i] <= arr[i+1]){
                arr[i] = arr[i+1]+1;
                sum++;
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
        
    }
};