class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int R = numbers.size()-1;
        int L = 0;
        while(L < R){

            int sum = numbers[L] + numbers[R];

            if( sum == target){
                return {L+1,R+1};
            }

            if(sum < target){
                L++;
            }

            if(sum > target){
                R--;
            }

        }

        return {0,0};
        
    }
};
