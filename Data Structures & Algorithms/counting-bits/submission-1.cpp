class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> resultArr;

        for(int i=0; i<=n; i++){
            int count = 0;
            int temp = i;
            while(temp>0){
                if((temp & 1) == 1){
                    count++;
                }
                temp = temp >> 1;
            }
            resultArr.push_back(count);
        }
        return resultArr;
    }
};
