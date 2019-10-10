class Solution {
public:
    /* 
     * Complexity: O(nlgk)
     * Space: O(k)
     */
    struct compare {
        bool operator()(const vector<int>& p1, vector<int>& p2){
            long dist1 = p1[0] * p1[0] + p1[1] * p1[1];
            long dist2 = p2[0] * p2[0] + p2[1] * p2[1];
            return dist1 < dist2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare>max_heap;
        for(int i = 0; i < points.size(); ++i){
            max_heap.push(points[i]);
            while(max_heap.size() > K) {
                max_heap.pop();
            }
        }
        vector<vector<int>>ans(max_heap.size());
        copy(&(max_heap.top()), &(max_heap.top()) + max_heap.size(), &ans[0]);
        return ans;
    }
};
