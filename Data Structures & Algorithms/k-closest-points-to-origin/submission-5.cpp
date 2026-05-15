class DistanceComparator{
    public:
    double calculateDistance(const vector<int>& point) const {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    bool operator()(const vector<int>& firstPoint, const vector<int>& secondPoint) const {
        return calculateDistance(firstPoint) < calculateDistance(secondPoint);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<vector<int>, vector<vector<int>>, DistanceComparator> kClosestQ;
        vector<vector<int>> result;
        DistanceComparator comparator;

        // for(auto point : points){
        //     kClosestQ.push({point[0],point[1]});
        // }

        for(auto point : points){
            if(kClosestQ.size() < k){
                kClosestQ.push({point[0],point[1]});
            }else if(comparator.calculateDistance(point) < comparator.calculateDistance(kClosestQ.top())){
                kClosestQ.pop();
                kClosestQ.push(point);
            }
        }

        for(int i=0; i<k; i++){
            result.push_back(kClosestQ.top());
            kClosestQ.pop();
        }
        return result;
    }



};
