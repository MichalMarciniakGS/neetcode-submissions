class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(stones.begin(),stones.end());
        int i = 0;

        while(pq.size() > 1){
            int heaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();
            
            int smashingResult = heaviest - secondHeaviest;

            if(smashingResult != 0){
                pq.push(smashingResult);
            }

        }

        if(!pq.empty()){
            return pq.top();
        }
        return 0;
        

    }
};
