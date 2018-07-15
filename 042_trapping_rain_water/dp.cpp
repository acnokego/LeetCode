class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   *
   * Actually, it is not dp since it doesn't separate the prob into sub-probs.
   * just using array to store some values.
   * For each elements in height, the level of water it can trap is equal to the
   * minimum of maximum height of bars on its both side minus its own weight;
   */
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left(size), right(size);
        left[0] = height[0];
        // used to store the maximum left for each element
        for(int i = 1; i < size; ++i)
            left[i] = max(left[i-1], height[i]);
        right[size-1] = height[size-1];
        // used to store the maximum right for each element
        for(int i = size - 2; i >= 0; --i){
            right[i] = max(right[i+1], height[i]);
        }
        for(int i = 0; i < size; ++i){
            ans += min(right[i], left[i]) - height[i];
        }
        return ans;
    }
};
