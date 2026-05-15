// Memoization Solution for Leetcode 518 - Coin Change II
// Problem: Count number of ways to make change for given amount using unlimited coins
// Global cache to store previously computed results across all instances
// Key: string representation of "index-amount" state  
// Value: number of ways to make change for that specific state
class Solution {

unordered_map<string,int> cache;

public:
    int change(int amount, vector<int>& coins) {
        // Sort coins in ascending order to maintain consistent ordering
        // This helps avoid counting duplicate combinations like [1,2] and [2,1]
        sort(coins.begin(), coins.end());
        
        // Start the recursive exploration from index 0 (first coin) with full amount
        return dfs(coins, 0, amount);
    }
    int dfs(const vector<int>& coins, int i, int a){
        // Base case 1: Perfect match - we've made exact change
        // When remaining amount is 0, we found one valid combination
        if(a == 0){
            return 1;  // Return 1 way to make amount 0 (use no more coins)
        }
        
        // Base case 2: Ran out of coin types to consider
        // If we've exhausted all coin denominations without reaching amount 0
        if(i >= coins.size()){
            return 0;  // Return 0 ways (impossible to make remaining amount)
        }
        // Create unique key for this state (index, amount)
        // Using string concatenation with delimiter to prevent hash collisions
        string key = to_string(i) + "-" + to_string(a);
        
        // Check if we've already computed this state (memoization lookup)
        // If so, return the cached result to avoid redundant computation
        if(cache.count(key)){
            return cache[key];
        }
        // Initialize result counter for this recursive call
        int res = 0;
        
        // Check if current coin value doesn't exceed remaining amount
        if(a >= coins[i]){
            // Decision tree: Two mutually exclusive choices
            // Choice 1: Skip current coin type entirely (move to next coin index)
            // Choice 2: Use current coin type (stay at same index, reduce amount)
            res = dfs(coins, i+1, a) + dfs(coins, i, a-coins[i]);
        }
        // If current coin is too large (a < coins[i]), res remains 0
        // This implicitly means "skip this coin" - no ways possible
        
        // CRITICAL FIX: Cache the result REGARDLESS of which path was taken
        // This ensures ALL recursive states get memoized, not just "use coin" cases
        cache[key] = res;
        
        // Return total number of valid combinations found in this branch
        return res;
    }
};