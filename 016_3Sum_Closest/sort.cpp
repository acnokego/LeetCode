class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(1)
     */
    int threeSumClosest(vector<int>& nums, int target) {
        int min_dist = INT_MAX;
        int closest_sum = 0;
        sort(nums.begin(), nums.end());
        int first = 0;
        while(first < nums.size()){
            int second = first + 1;
            int third = nums.size() - 1;
            while(second < third){
                int temp = nums[first] + nums[second] + nums[third];
                if(temp == target){
                    return target;
                } else if(temp > target){
                    int dist = abs(temp - target);
                    if(dist < min_dist) {
                        min_dist = dist;
                        closest_sum = temp;
                    }
                    --third;
                    while(third >= 0 && nums[third + 1] == nums[third]) --third;
                } else {
                    int dist = abs(temp - target);
                    if(dist < min_dist){
                        min_dist = dist;
                        closest_sum = temp;
                    }
                    ++second;
                    while(second < nums.size() && nums[second-1] == nums[second]) ++second;
                }
            }
            ++first;
            while(first < nums.size() && nums[first-1] == nums[first]) ++first;
        }
        return closest_sum;
    }
};
