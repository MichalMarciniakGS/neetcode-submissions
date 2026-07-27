class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> cars;
        stack<double> stk;

        for(size_t i=0; i<position.size(); ++i){
            cars.push_back({position[i],speed[i]});
        }

        std::sort(cars.rbegin(),cars.rend()); //reverse sort order


        for(const auto& car : cars){
            double time = (double)(target - car.first)/car.second;
            // double currTime = stk.top();
            if(stk.empty() || stk.top() < time){
                stk.push(time);
            }

        }

        return stk.size();

    }
};
