class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result = {{}};

        for(auto num : nums){
            int length = result.size();

            for(int i = 0; i<length; i++){
                vector<int> subset = result[i];
                subset.push_back(num); 
                result.push_back(subset);
            }
        }
        return result;

    }
};
