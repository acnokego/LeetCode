// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
/*
 * Complexity : O(lgn)
 * Space: O(1)
 */
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while(start < end){
            // to prevent overflow, you can not use (start + end) / 2 here
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)) end = mid;
            else start = mid + 1;
        }
        return start;   
    }
};
