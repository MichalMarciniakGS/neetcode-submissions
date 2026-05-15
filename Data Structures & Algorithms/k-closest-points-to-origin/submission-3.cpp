class DistanceComparator{
    private:
    double calculateDistance(const vector<int>& point){
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
    public:
    bool operator()(const vector<int>& firstPoint, const vector<int>& secondPoint){
        return calculateDistance(firstPoint) > calculateDistance(secondPoint);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<vector<int>, vector<vector<int>>, DistanceComparator> kClosestQ;
        vector<vector<int>> result;

        for(auto point : points){
            kClosestQ.push({point[0],point[1]});
        }

        for(int i=0; i<k; i++){
            result.push_back(kClosestQ.top());
            kClosestQ.pop();
        }
        return result;
    }



};
