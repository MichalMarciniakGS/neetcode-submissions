// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();
        std::vector<vector<Pair>> result = {};

        for(int i = 0; i < n; i++){
            int j = i-1;

            while(j >= 0 && pairs[j].key > pairs[j+1].key){
                std::swap(pairs[j],pairs[j+1]);
                j--;
            }

            result.push_back(pairs);
        }

        return result;
    }
};
