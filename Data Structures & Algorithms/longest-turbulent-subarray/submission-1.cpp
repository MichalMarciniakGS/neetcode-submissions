class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int L=0;
        int curRes = 0, maxRes=1;
        string sign = "";

        // [2,4,3,1,2,1,1]
        // [ < > > < ]
        //  L    R

        for(int R=1; R<arr.size(); R++){
            
            if(arr[R-1] > arr[R] && sign != ">"){
                // curRes++;
                maxRes = max(maxRes, R-L+1);
                sign = ">";
            }else if(arr[R-1] < arr[R] && sign != "<"){
                // curRes++;
                maxRes = max(maxRes, R-L+1);
                sign = "<";
            }else{
                if(arr[R-1] == arr[R]){
                    L=R;
                    sign = "";
                }else{
                    L = R-1;
                }
            }
        }
        return maxRes;

    }
};