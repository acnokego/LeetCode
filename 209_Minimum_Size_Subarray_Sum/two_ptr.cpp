class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int arraySum = 0;
        int minLength = n + 1;

        while(end < n){
            arraySum += nums[end];
            // increasing end until the sum is bigger than s
            if(arraySum >= s){
                minLength = min(end - start + 1, minLength);
                // increasing start to update the minLength until the sum is
                // smaller than s;
                while((arraySum - nums[start]) >= s && start <= end){
                    arraySum -= nums[start];
                    start += 1;
                    minLength = min(end - start + 1, minLength);
                   
                }
            }
            ++end;
        }
        
        return (minLength == n+1) ? 0 : minLength;
    }
};
