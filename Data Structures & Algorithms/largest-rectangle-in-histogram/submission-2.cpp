class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stk;  // index,height

        for (int i{0}; i < heights.size(); i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                auto poppedPair = stk.top();
                stk.pop();
                maxArea = max(maxArea, poppedPair.second * (i - poppedPair.first));
                start = poppedPair.first;
            }
            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            auto [idx, h] = stk.top();
            stk.pop();
            maxArea = max(maxArea, h * ((int)heights.size() - idx));
        }

        return maxArea;
    }
};
