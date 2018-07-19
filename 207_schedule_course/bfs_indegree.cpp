class Solution {
  /*
   * Complexity: O(V + E)
   * Space: O(V) or O(E)
   */
public:
    // calulate in degrees
    void compute_in(vector<int>& degrees, vector<vector<int>>& edges){
        int n = edges.size();
        for(int i = 0; i < n; ++i){
            for(auto& out: edges[i])
            ++degrees[out];
        }
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > edges (numCourses);
        for(auto& p : prerequisites){
            edges[p.second].push_back(p.first);
        }
        vector<int>degrees(numCourses);
        compute_in(degrees, edges);
        // push vertex with zero indegree
        // zero in degree: starting vertex of a path.
        queue<int>zero_in;
        for(int i = 0; i < numCourses; ++i){
            if(!degrees[i])zero_in.push(i);
        }
        int count = 0;
        while(!zero_in.empty()){
            int i = zero_in.front();
            ++count;
            zero_in.pop();
            int edge = edges[i].size();
            // remove i and subtract in degree 
            for(int j = 0; j < edge; ++j){
                --degrees[edges[i][j]];
                if(degrees[edges[i][j]] == 0) zero_in.push(edges[i][j]);
            }
        }
        if(count == numCourses) return true;
        // if there is no vertex with 0 in degress there must be cycles in the
        // graph
        else return false;
    }
};
