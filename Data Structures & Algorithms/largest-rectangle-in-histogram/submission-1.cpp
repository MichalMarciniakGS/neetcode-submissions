class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int currMinHeight = 0;
        int maxArea = 0;
        priority_queue<int> allAreas;


        for(int i=0; i<heights.size(); i++){

            currMinHeight = heights[i];

            for(int j=i; j<heights.size(); j++){

                currMinHeight = min(currMinHeight,heights[j]);
                int currWidth = j-i+1;
                maxArea = max(maxArea, currMinHeight * currWidth);
            }
        }

        return maxArea;
        
    }
};
