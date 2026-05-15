class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int L=0, R=numbers.size()-1;
        vector<int> res;

        while (L<R){

            int currSum = numbers[L]+numbers[R];

            if(currSum > target){
                R--;
            }else if(currSum < target){
                L++;
            }else{
                return {L+1,R+1};
            }

        }

        return {-1,-1};
        
    }
};
