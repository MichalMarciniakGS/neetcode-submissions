class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> curComb;
        helper(1, n, k, curComb);
        return res;
    }

    void helper(int i, int n, int k, vector<int>& curComb){

        if(curComb.size() == k){
            res.push_back(curComb);
            return;
        }

        for(i; i<=n; i++){
            curComb.push_back(i);
            helper(i+1,n,k,curComb);
            curComb.pop_back();
        }


    }
};