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
    vector<Pair> quickSort(vector<Pair>& pairs) { 
        //In place
        quickSortHelper(pairs, 0, pairs.size()-1);
        return pairs;


    }

    void quickSortHelper(vector<Pair>& pairs, int s, int e){

        //base case (array length is 1 because it cannot be more sorted)
        if (e-s+1 <= 1){ //length of array
            return;
        }

        auto pivot = pairs[e];
        auto left = s;

        for(int i = s; i< e; i++){
            //Partition
            if (pairs[i].key < pivot.key){
                auto tmp = pairs[left];
                pairs[left] = pairs[i];
                pairs[i] = tmp;
                left++;
            }
        }
        pairs[e] = pairs[left];
        pairs[left] = pivot;



        quickSortHelper(pairs, s, left-1); //Sort on the left-half
        quickSortHelper(pairs, left+1, e); //Sort on the right-half
    }
};
