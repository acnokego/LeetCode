class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            // calculate the trapped water horizontally.
            // push index in the stack.
            // to check if the previous bars(top) is smaller than current bar
            // if it is, the top might be bounded by the current bar and
            // previous bar. 
            // the previous bar must be bigger than the top, if it's smaller,
            // it must have been popped already.
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                // pop the top
                st.pop();
                if (st.empty())
                    break;
                // calulate the dist. between current bar and previous one.
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                // add the water horizontally.
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};
