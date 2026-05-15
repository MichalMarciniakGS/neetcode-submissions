class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        using pii = pair<int,int>;

        unordered_map<int,int> counter;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(int num : nums){
            counter[num]++;
        }

        for(const auto& [first,sec] : counter){
            pq.push({sec, first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res = {};
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
        
    }
};
