class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<double> calcDistances;
        vector<pair<double,pair<int,int>>> pairs;

        for(auto point: points){
            // k--;
            double x = point[0];
            double y = point[1];

            double result = sqrt(x*x + y*y);
            calcDistances.push_back(result);

            pairs.push_back({result, {x,y}});

        }

        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b){
            return a.first < b.first;
        });

        vector<vector<int>> result;

        for(int i = 0; k > i; i++){
            result.push_back({pairs[i].second.first,pairs[i].second.second});
        }

        return result;

    }
};
