class Solution {
public:
 /*
  * Complexity: O(k*N)
  * Space: O(1)
  */
    void rotate(vector<int>& nums, int k) {
        for(int step = 0; step < k; ++step){
            int tmp_element = nums.back();
            int last_element;
            for(int i = 0; i<nums.size(); ++i){
                last_element = tmp_element;
                tmp_element = nums[i];
                nums[i] = last_element;
            }   
        }
    }
};
