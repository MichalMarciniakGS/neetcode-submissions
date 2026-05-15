class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> unMap = {};

        for(auto num : nums){
            unMap[num]++;
        }

        std::vector<std::pair<int,int>> result(k);

        std::partial_sort_copy(unMap.begin(), unMap.end(),
        result.begin(), result.end(),
        [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        std::vector<int> keys(k);
        std::transform(result.begin(), result.end(), keys.begin(),
            [](const auto& p) { return p.first; });
        
        return keys;
    }
};
