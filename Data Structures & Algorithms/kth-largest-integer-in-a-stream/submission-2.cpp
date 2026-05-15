class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        
        this->kth = k;

        for(auto num: nums){
            pq.push(num);  // 1,2,3,3
        };

    }
    
    int add(int val) {
        
        pq.push(val); // 1,2,3,3,4 size=5

        while(kth < pq.size()){
            pq.pop();
        }

        return pq.top();

    }
};
