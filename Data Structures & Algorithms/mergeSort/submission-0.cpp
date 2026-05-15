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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        return mergeSortHelper(pairs, 0, pairs.size()-1);
    }

    vector<Pair> mergeSortHelper(vector<Pair>& pairs, int s, int e){
        if (e-s + 1 <= 1){
            return pairs;
        }
        int m = (s+e)/2;

        mergeSortHelper(pairs, s, m);
        mergeSortHelper(pairs, m+1, e);
        merge(pairs, s, m, e);

        return pairs;
    }
    
    void merge(vector<Pair>& arr, int s, int m, int e){
        vector<Pair> L(arr.begin()+s, arr.begin()+ m+1);
        vector<Pair> R(arr.begin()+m+1, arr.begin()+e+1);

        int i = 0; //index for L
        int j = 0; //index for R
        int k = s; //index for arr

        while( i < L.size() && j < R.size()){
            if (L[i].key <= R[j].key){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < L.size()){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j < R.size()){
            arr[k] = R[j];
            j++;
            k++;
        }

    }
};
