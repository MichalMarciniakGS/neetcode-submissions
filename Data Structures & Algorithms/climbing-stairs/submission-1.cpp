class Solution {
    unordered_map<int,int> cache;

public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        if(cache.count(n)){
            return cache[n];
        }


        cache[n] = climbStairs(n-1) + climbStairs(n-2);
        return cache[n];
    }
};
