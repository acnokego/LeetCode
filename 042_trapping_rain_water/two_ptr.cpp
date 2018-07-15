class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        int left = 0, right = size - 1;
        int max_left = 0, max_right = 0;
        while(left < right){
            // dependent on left (min)
            // keep moving left until height[left] > height[right]
            // then we start to move right to check where the height[right] >
            // height[left] and then it would be dependent on left again
            if(height[left] < height[right]){
                if(height[left] > max_left) max_left = height[left];
                else ans += (max_left - height[left]);
                ++left;
            }
            // dependent on right (min)
            else{
                if(height[right] > max_right) max_right = height[right];
                else ans += (max_right - height[right]);
                --right;
            }
        }
        return ans;
    }
};
