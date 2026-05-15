class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq(nums.begin(),nums.end());

        // 5,4,3,2,1

        for(int i=1; i<k; i++){
            pq.pop();
        }
        return pq.top();

    }
};
