class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        if (arr.empty()){
            return 0;
        }

        int res = 1;
        int L=0;
        string sign = "";

        for(int R=1; R<arr.size(); R++){

            if(arr[R-1] > arr[R] && sign != ">"){
                sign = ">";
            }else if(arr[R-1] < arr[R] && sign != "<"){
                sign = "<";
            }else{
                if(arr[R-1] == arr[R]){
                    L=R;
                    sign = "";
                }else{
                    L=R-1;
                }
            }
            res = max(res, R-L+1);

        }
        return res;

    }
};