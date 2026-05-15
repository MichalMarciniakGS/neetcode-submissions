class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int L=0;
        int length = 1;
        string sign = "";

        for(int R=1; R<arr.size(); R++){

            if(arr[R-1] > arr[R] && sign != ">"){
                
                length = max(length, R-L+1);
                sign = ">";

            }else if(arr[R-1] < arr[R] && sign != "<"){

                length = max(length, R-L+1);
                sign = "<";
            }else{

                if(arr[R-1] == arr[R]){
                    L = R;
                    sign = "";
                }else{
                    L = R-1;
                }

            }

        }
        return length;
        
    }
};