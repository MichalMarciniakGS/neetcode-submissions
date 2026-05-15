class Solution {

    vector<vector<int>> res;
    unordered_map<int,int> cache;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        for(auto n : nums){
            cache[n]++;
        }

        // num-1 cnt-2
        // num-2 cnt-1

        vector<int> curPer;

        helper(nums, curPer);

        return res;

    }

    void helper(const vector<int>& nums, vector<int>& curPer){

        if(curPer.size() == nums.size()){
            res.push_back(curPer);
            return;
        }

        for(auto [num, cnt] : cache){
            if(cnt > 0){
                curPer.push_back(num);
                cache[num]--;

                helper(nums,curPer);

                curPer.pop_back();
                cache[num]++;


            }
        }


    }
};