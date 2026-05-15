class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> curSubset;
        helper(1,n,k,res,curSubset);
        return res;
        
    }

    void helper(int i, int n, int k, vector<vector<int>>& res, vector<int> curSubset){

        if(curSubset.size() == k){
            res.push_back(curSubset);
            return;
        }

        if(i>n){
            return;
        }

        for(int j=i; j<=n; j++){
            curSubset.push_back(j);
            helper(j+1,n,k,res,curSubset);
            curSubset.pop_back();
        }

    }
};