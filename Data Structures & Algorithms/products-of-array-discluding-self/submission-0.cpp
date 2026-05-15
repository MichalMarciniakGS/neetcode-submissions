class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        //original [1,2,4,6]
        //prefix   [1,1,2,8] od lewej (wszystko co jest po lewo od danej liczby w indeksie i)
        for(int i = 1; i<n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        //sufix [48,24,6,1] od prawej (wszystko co jest po prawo od danej liczby w indeksie i)
        for(int j=n-2; j>=0; j--){
            suffix[j] = nums[j+1] * suffix[j+1];
        }

        //result
        for(int i=0; i<n; i++){
            res[i] = prefix[i] * suffix[i];
        }

        return res;

    }
};
