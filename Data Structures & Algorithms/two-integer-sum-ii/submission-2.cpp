class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int L=0, R=numbers.size()-1;
        vector<int> res;

        while(L<R){

            if(numbers[L] + numbers[R] < target){
                L++;
            }else if(numbers[L] + numbers[R] > target){
                R--;
            }else{
                return {L+1,R+1};
            }

        }
        return {-1,-1};
        
    }
};
