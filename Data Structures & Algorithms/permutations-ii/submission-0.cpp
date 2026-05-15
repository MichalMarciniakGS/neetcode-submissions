class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> perms = {{}};
        vector<vector<int>> res;
        set<vector<int>> seno;

        for(int n : nums){
            vector<vector<int>> nextPerms;
            for(vector<int> p : perms){
                for(int i=0; i<p.size()+1; i++){
                    vector<int> pCopy(p);
                    pCopy.insert(pCopy.begin() + i, n);
                    nextPerms.push_back(pCopy);
                    if(pCopy.size() == nums.size()){
                    seno.insert(pCopy);
                    }
                }
            }
            perms = nextPerms;
        }

        return vector<vector<int>>(seno.begin(), seno.end());
        
    }
};