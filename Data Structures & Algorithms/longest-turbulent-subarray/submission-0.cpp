class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int L=0, R=1;
        int result = 1;
        string prev = "";

        while(R < arr.size()){
            if(arr[R-1] > arr[R] && prev != ">"){
                result = max(result, R-L+1);
                prev = ">";
                R++;
            }else if(arr[R-1] < arr[R] && prev != "<"){
                result = max(result, R-L+1);
                prev = "<";
                R++;
            }else{
                if(arr[R] == arr[R-1]){
                    R = R+1;
                }
                L = R - 1;
                prev = "";
            }
        }
        return result;
    }
};