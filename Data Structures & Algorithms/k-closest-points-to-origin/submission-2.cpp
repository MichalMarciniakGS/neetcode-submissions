class CustomComparator{
    private:
    double calculateDistance(const vector<int>& points) const{
        return sqrt(points[0]*points[0] + points[1]*points[1]);
    }

    public:
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const{
        return calculateDistance(a) > calculateDistance(b);
    }

};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>, vector<vector<int>>, CustomComparator> pq;
        vector<vector<int>> result;

        for(auto pointPair : points){
            pq.push(pointPair); // [0,2],[2,2],[4,4] k=1
        }

        for(int i=0; i<k; i++){
            result.push_back(pq.top());
            pq.pop();
        }

        return result;

    }
};
