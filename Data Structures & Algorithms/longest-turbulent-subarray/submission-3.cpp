class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int L=0;
        int result = 0, length=1;
        string sign = "";

        // 1 2 1 0 3
        // [< > > <]
        // L     R   
        // 0 1 2 3 4 indexes

        for(int R=1; R<arr.size(); R++){

            if(arr[R-1] > arr[R] && sign != ">"){
                result++;
                sign = ">";
            }else if(arr[R-1] < arr[R] && sign != "<"){
                result++;
                sign = "<";
            }else{

                if(arr[R-1] == arr[R]){
                    L=R;
                }else{
                    L = R-1;
                }
            }

            length = max(R-L+1, length);

        }

        return length;

    }
};