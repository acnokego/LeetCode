class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n){
            return vector<int>(2, -1);
        }
        int start = 0, end = n-1, right, left;
        // find the start of the range
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] >= target) end = mid - 1;
            // if mid < target, then we start from the next pos. that is >=
            // target
            // if there is no target than the left would be the first element 
            // bigger than the target
            else start = mid + 1;
        }
        left = start;
        end = n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] > target) end = mid - 1;
            // if mid <= target, we start from the next pos that would be bigger
            // than the target
            // if there is no target than this condition would never be meet
            // this left would be equal to right
            else start = mid + 1;
        }
        right = start;
        return (left == right ? vector<int>{-1,-1} : vector<int>{left, right - 1});
    }
};
