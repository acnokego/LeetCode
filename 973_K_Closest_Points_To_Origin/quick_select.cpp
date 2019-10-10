class Solution {
public:
    /*
     * Complexity: O(n) -> n + 1/2n +...., worst case O(n^2)
     * Space: O(1)
     */
    bool compare(const vector<int>& pivot, const vector<int>& p){
        long dist1 = pivot[0] * pivot[0] + pivot[1] * pivot[1];
        long dist2 = p[0] * p[0] + p[1] * p[1];
        return dist1 > dist2;
    }
    int quick_select(vector<vector<int>>& points, int start, int end){
        int pivot_idx = start + (end - start) / 2;
        vector<int> pivot = points[pivot_idx];
        swap(points[pivot_idx], points[end]);
        int i = start, j = start;
        for(;j < end; ++j){
            if(compare(pivot, points[j])){
                swap(points[i], points[j]);
                ++i;
            }
        }
        swap(points[end], points[i]);
        return i;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        int start = 0, end = points.size() - 1;
        while(start < end){
            int idx = quick_select(points, start, end);
            if(idx == K) break;
            else if (idx > K){
                end = idx - 1;
            } else {
                start = idx + 1;
            }
        }
        vector<vector<int>>ans(K);
        copy(points.begin(), points.begin() + K, ans.begin());
        return ans;
    }
};
