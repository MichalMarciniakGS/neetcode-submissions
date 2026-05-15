class Solution {
public:
    int climbStairs(int n) {
        
        if(1 >= n){
            return 1;
        }

        return climbStairs(n-1) + climbStairs(n-2);

    }
};
