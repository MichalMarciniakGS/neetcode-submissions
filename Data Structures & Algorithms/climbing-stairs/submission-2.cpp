class Solution {
    unordered_map<int, int> visited;
public:
    int climbStairs(int n) {
        
        if(n <= 2){
            return n;
        }

        if(visited.count(n)){
            return visited[n];
        }

        visited[n] = climbStairs(n-1) + climbStairs(n-2);
        return visited[n];
    }
};
