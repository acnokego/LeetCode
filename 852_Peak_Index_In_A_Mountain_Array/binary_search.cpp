class Solution {
public:
    /*
     * Complexity: O(lgn)
     * SpaceL O(1)
     */
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0, end = A.size() - 1;
        
        while(start < end){
            int mid = (end - start) / 2 + start;
            if(A[mid] > A[mid+1]){
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
