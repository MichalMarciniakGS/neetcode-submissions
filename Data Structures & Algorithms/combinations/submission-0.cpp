class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> curSubset;
        helper(1,k,n,res,curSubset);
        return res;
        
    }

    void helper(int i, int k, int n, vector<vector<int>>& res, vector<int>& curSubset){

        if(curSubset.size() == k){
            res.push_back(vector<int>(curSubset));
            return;
        }

        if(i>n){
            return;
        }

        //Include:
        curSubset.push_back(i);
        helper(i+1,k,n,res,curSubset);

        //Exclude:
        curSubset.pop_back();
        helper(i+1,k,n,res,curSubset);

    }
};