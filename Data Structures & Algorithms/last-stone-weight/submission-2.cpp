class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1){

            int heaviest = pq.top();
            pq.pop();
            int scndHeaviest = pq.top();
            pq.pop();
            int diff = heaviest - scndHeaviest;
            
            if(diff != 0){
                pq.push(diff);
            }

        }

        if(!pq.empty()){
            return pq.top();
        }
        return 0;
        
    }
};
