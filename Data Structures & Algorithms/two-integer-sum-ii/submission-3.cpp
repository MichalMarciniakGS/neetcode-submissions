class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int L=0, R=numbers.size()-1;


        while(L<R){
            int sum = numbers[L] + numbers[R];
            if(sum > target){
                R--;
            }else if(sum < target){
                L++;
            }else{
                return {L+1,R+1};
            }

        }
        
    }
};
