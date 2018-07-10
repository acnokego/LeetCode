class Solution {
  /*
   * Complexity: O((n+m)*lg(max-min))
   * Space: O(1)
   */
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if( n == 0 ) return 0;
        int low = matrix[0][0];
        int high = matrix[n-1][n-1] + 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            int count = 0, j = n-1;
            // get the order of mid: count
            // the element iterating order is like
            // x x v
            // x v x
            // v x x
            // the v indicate being checked
            // the column of next row should be <= previous row
            for(int i = 0; i < n; ++i){
                while( j >= 0 && matrix[i][j] > mid) --j;
                count += (j+1);
            }
            // if the order of mid < k, then the range become [mid+1, high)
            if(count < k) low = mid + 1;
            // else if the order of mid >= k then the range become [low, mid)
            else high = mid;
        }
        return low;
    }
};
