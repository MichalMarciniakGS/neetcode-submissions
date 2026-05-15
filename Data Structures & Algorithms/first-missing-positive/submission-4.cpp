class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // Get array size - the first missing positive must be in range [1, n+1]
        // because in best case array contains all numbers 1 to n, making n+1 the answer
        int n = nums.size();

        // Phase 1: Cyclic Sort - Place each valid number in its correct position
        // For number x, correct position is index x-1 (since array is 0-indexed)
        // Goal: nums[0] should be 1, nums[1] should be 2, etc.
        for(int i=0; i<n; i++){
            // Keep swapping current element until it's in correct position or invalid
            // Conditions: number must be positive, within range [1,n], and not already in correct spot
            while(nums[i] > 0 && nums[i] <= n 
            && nums[i] != nums[nums[i]-1]){
                // Swap current number with element at its target position
                // nums[i] should go to index nums[i]-1, so swap with nums[nums[i]-1]
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        // Phase 2: Find First Missing - Check each position for correct value
        // After cyclic sort, nums[i] should equal i+1 if number i+1 exists
        for(int i=0; i<n; i++){
            // If position i doesn't contain expected value i+1
            if(nums[i] != i+1){
                // Then i+1 is the first missing positive integer
                return i+1;
            }
        }

        // All positions 0 to n-1 contain correct values 1 to n
        // So the first missing positive is n+1
        return n+1;
        
    }
};
