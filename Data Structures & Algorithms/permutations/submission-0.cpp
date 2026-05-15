class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> perms = {{}};

        for(int n : nums){
            vector<vector<int>> nextPerms;
            for(vector<int> p : perms){
                for(int i=0; i<p.size()+1; i++){
                    vector<int> pCopy = p;
                    pCopy.insert(pCopy.begin()+i, n);
                    nextPerms.push_back(pCopy);
                }
            }
            perms = nextPerms;
        }
        return perms;
        
    }
};
