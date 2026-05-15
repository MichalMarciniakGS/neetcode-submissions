class KthLargest {
    int kLargest;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {

        for(auto num : nums){
            pq.push(num);
        }

        kLargest = k;
        
        // result = nums;
        // make_heap(result.begin(), result.end());
        // while(result.size() > k){
        //     result.pop_back();
        // }

        kLargest = k;
    }
    
    int add(int val) {

        pq.push(val);
        while(pq.size() > kLargest){
            pq.pop();
        }
        // result.push_back(val);
        // make_heap(result.begin(), result.end());

        return pq.top();
    }
};
