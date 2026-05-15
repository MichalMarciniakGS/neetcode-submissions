class CompareDistance{
    private:
    double calculateDistance(const vector<int>& nums) const{
        return sqrt(nums[0]*nums[0] + nums[1]*nums[1]);
    }

    public:
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const{
        return calculateDistance(a) > calculateDistance(b);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // int distance = sqrt(points[i][0]^2 + points[i][1]^2);

        priority_queue<vector<int>, vector<vector<int>>, CompareDistance> pq;

        for(auto point : points){
            pq.push({point[0],point[1]});
        } 

        vector<vector<int>> result;

        for(int i = 0; i<k; i++){
            result.push_back(pq.top());
            pq.pop();
        }

        return result;

    }
};
