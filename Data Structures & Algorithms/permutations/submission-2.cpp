class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {    

        return helper(0,nums);
        
    }

    vector<vector<int>> helper(int i, const vector<int>& nums){

        if(i == nums.size()){
            return {{}};
        }

        vector<vector<int>> res;

        vector<vector<int>> perms = helper(i+1,nums);

        for(vector<int> curPerm : perms){
            for(int j=0; j<curPerm.size() + 1; j++){
                vector<int> permCopy(curPerm);
                permCopy.insert(permCopy.begin() + j, nums[i]);
                res.push_back(permCopy);
            }


        }
        return res;

    }
};
