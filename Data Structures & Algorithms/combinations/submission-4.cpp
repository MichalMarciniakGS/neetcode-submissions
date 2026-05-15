class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> curComb;

        helper(1,n,k,res,curComb);

        return res;
        
    }

    void helper(int i, int n, int k, vector<vector<int>>& res, vector<int> curComb){

        if(curComb.size() == k){
            res.push_back(curComb);
            return;
        }

        if(i>n){
            return;
        }

        curComb.push_back(i);
        helper(i+1,n,k,res,curComb);

        curComb.pop_back();
        helper(i+1,n,k,res,curComb);

    }
};