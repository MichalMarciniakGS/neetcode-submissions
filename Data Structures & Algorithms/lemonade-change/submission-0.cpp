class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for(const auto& bill : bills){

            if(bill == 5){
                five += 1;
            }

            else if(bill == 10){
                if(five > 0){
                    five -= 1;
                    ten += 1;
                }else{
                    return false;
                }
            }

            else if(bill == 20){
                if(ten > 0 && five > 0){
                    ten -= 1;
                    five -= 1;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }

        }
        return true;
        
    }
};