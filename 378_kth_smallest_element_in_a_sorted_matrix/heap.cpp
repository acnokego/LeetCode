class Solution {
  /*
   * Complexity: O(n + klgn)
   * Space : O(n)
   * push the first row in min heap first.
   * and pop the top, then push matrix[i+1][j], where i, j is the index of top.
   * since we have to compare the max value of this row and the min value of
   * next row
   */
public:
    struct tuple{
        int x;
        int y;
        int val;
        tuple(int x, int y, int val): x(x), y(y), val(val){}
        bool operator > (const struct tuple& other) const{
            return (val > other.val);
        }
        
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if( n == 0 ) return 0;
        priority_queue<tuple, vector<tuple>, greater<tuple> > pq;
        for(int i = 0; i < n; ++i) pq.push(tuple(0, i, matrix[0][i]));
        for(int i = 0; i < k-1; ++i){
            tuple t = pq.top();
            pq.pop();
            if(t.x == n-1) continue;
            pq.push(tuple(t.x + 1, t.y, matrix[t.x+1][t.y]));
        }
        return pq.top().val;
    }
};
