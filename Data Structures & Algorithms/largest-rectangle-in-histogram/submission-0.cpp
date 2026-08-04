class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int currMinHeight = 0;
        int currWidth = 0;
        priority_queue<int> allAreas;


        for(int i=0; i<heights.size(); i++){

            currMinHeight = heights[i]; // 7 | 1 | 7 | 2
            currWidth = 1; // 1 | 1 | 1 | 1

            for(int j=i; j<heights.size(); j++){

                currMinHeight = min(currMinHeight,heights[j]); //7,1,1,1,1,1 | 1,1,1,1,1 | 7,2,2,2 | 2,2,2
                currWidth = max(j-i+1,1); //1,2,3,4,5,6 | 1,2,3,4,5 | 1,2,3,4 | 1

                allAreas.push(currMinHeight*currWidth); //7,2,3,4,5,6 | 1,2,3,4,5 | 7,4,6,8 | 2
            }
        }

        return allAreas.top();
        
    }
};
