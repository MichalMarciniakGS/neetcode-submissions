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

        if(allSumHalf < 0){
            return false;
        }

        if(i >= nums.size()){
            return allSumHalf == 0;
        }

        if(memo[i][allSumHalf] != -1){
            return memo[i][allSumHalf];
        }

        memo[i][allSumHalf] = helper(i+1, nums, allSumHalf) || helper(i+1, nums, allSumHalf-nums[i]);
        return memo[i][allSumHalf];
    }
};
