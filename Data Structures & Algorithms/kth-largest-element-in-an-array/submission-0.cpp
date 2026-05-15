class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;

        for(auto num : nums){
            pq.push(num);
        }

        for(int i = 1; k > i; i++){
            pq.pop();
        }

        return pq.top();

    }
};
