class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   *
   * Calulate all rectangles' areas that has each bars as their heights.
   * For each rectangles, we need to find the bars that are smaller than the
   * heights on both sides to decide its width.
   */
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>s; 
        int maxArea = 0;
        
        for(int i = 0; i <= n; ++i){
            // for the last bar
            int h = ( i == n ? 0 : heights[i]); // pop till s is empty
            if(s.empty() || h >= heights[s.top()]){
                // store heights of increasing order
                s.push(i);
            }
            else{
                // calulate the area when using each bar as the lowest height
                int lowest = s.top();
                s.pop();
                // find the range of width from s.top() to i. 
                // s.top -> the last index that is lower than the current height.
                // i the next index that is lower than the current height
                maxArea = max(maxArea, heights[lowest]*( s.empty() ? i : i - 1 - s.top() ));
                --i; // pop until there is a height that is smaller than h[i]
            }
        }
        
        return maxArea;
    }
};
