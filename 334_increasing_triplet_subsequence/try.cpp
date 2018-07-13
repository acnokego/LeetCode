class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) return false;
        // store the current minimun mid ( > min)
        int mid = INT_MAX;
        // store the current minimum number
        int min = INT_MAX;
        for(auto& n: nums){
            // update min
            if(n <= min) min = n;
            // update mid, if n > min and n < mid
            else if(n < mid) mid = n;
            // found the third element
            else if(n > mid){
                return true;
            }   
        }
        return false;
    }
};
