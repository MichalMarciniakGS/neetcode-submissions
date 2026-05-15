class Solution {
    // 2D memoization table to cache results of subproblems
    // memo[i][sum] stores result for: "can we achieve sum using elements from index i onwards?"
    // Values: -1 (not computed), 0 (false), 1 (true)
    vector<vector<int>> memo;

public:
    bool canPartition(vector<int>& nums) {
        // Calculate total sum of all elements in the array
        int allSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Early termination: if total sum is odd, partition into equal subsets is impossible
        // Two equal subsets must each have sum = totalSum/2, which requires even totalSum
        if(allSum % 2 != 0){
            return false;
        }

        // Target sum for each subset (half of total sum)
        int allSumHalf = allSum/2;
        
        // Initialize memoization table with -1 (uncomputed state)
        // Dimensions: [number of elements] x [target sum + 1]
        // +1 for sum because we need to handle sum=0 case (base case)
        memo.assign(nums.size(), vector<int>(allSumHalf+1, -1));
        
        // Start recursive solution from index 0, trying to achieve target sum
        return helper(0, nums, allSumHalf);
    }

    bool helper(int i, const vector<int>& nums, int allSumHalf){
        // Base case 1: Successfully found a subset with exact target sum
        // If remaining sum is 0, we've successfully partitioned
        if(allSumHalf == 0){
            return true;
        }

        // Base case 2: Exhausted all elements without reaching target sum
        // No more elements to consider, partition failed
        if(i >= nums.size()){
            return false;
        }

        // Memoization check: return cached result if already computed
        // Avoids redundant recursive calls for same (index, remaining_sum) state
        if(memo[i][allSumHalf] != -1){
            return memo[i][allSumHalf];
        }

        // Choice 1: Skip current element nums[i]
        // Move to next element while keeping same target sum
        bool skipResult = helper(i+1, nums, allSumHalf);
        if(skipResult){
            // Early termination optimization: if skipping works, cache and return immediately
            memo[i][allSumHalf] = 1;
            return true;
        }

        // Choice 2: Include current element nums[i] in our subset
        bool includeResult = false;
        int newSum = allSumHalf - nums[i];  // Reduce target by current element's value
        
        // Only attempt inclusion if it doesn't make sum negative
        // This prevents invalid states where we exceed our target
        if(newSum >= 0){
            includeResult = helper(i+1, nums, newSum);
        }

        // Cache the final result (0 for false, 1 for true) and return
        // This represents: "can we achieve allSumHalf using elements from index i onwards?"
        memo[i][allSumHalf] = includeResult ? 1 : 0;
        return includeResult;
    }
};
