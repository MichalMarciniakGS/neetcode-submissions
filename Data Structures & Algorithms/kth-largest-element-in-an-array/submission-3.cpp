class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        // [1,2,3,4] k=2 -> 3



        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();

    }
};
