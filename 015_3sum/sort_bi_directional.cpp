class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(1)
   * reference: 
   * https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments
   */
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0 ; i < size; ++i){
            int complement = -(nums[i]);
            int front = i + 1;
            int back = size - 1;
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum > complement) --back;
                else if(sum < complement) ++front;
                else{
                    vector<int>tri{nums[i], nums[front], nums[back]};
                    ans.push_back(tri);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == tri[1]) ++front;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && nums[back] == tri[2]) --back;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < size && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};
