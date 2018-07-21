class Solution {
  /*
   * Complexity: O(V + E)
   * Space: O(max(V,E))
   */
public:
    void cal_indegree(vector<int>& degrees, vector<vector<int>>& edges){
        int n = edges.size();
        for(int i = 0; i <n ;++i){
            for(auto& e : edges[i]){
                ++degrees[e];
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        // get adjacent list
        for(auto& p : prerequisites){
            edges[p.second].push_back(p.first);
        }
        // in-degree of each node
        vector<int>degrees(numCourses);
        cal_indegree(degrees, edges);
        vector<int>start_node;
        // get the start node of each connected component.
        for(int i = 0; i < numCourses; ++i){
            if(degrees[i] == 0) start_node.push_back(i);
        }
        vector<int>ans;
        for(int i = 0; i < start_node.size(); ++i){
            // for each component run bfs.
            queue<int>q;
            q.push(start_node[i]);
            // if there is a cycle there would be no vertex that has 0 in-degree
            // then the loop would end.
            while(!q.empty()){
                int course = q.front();
                q.pop();
                ans.push_back(course);
                for(int j = 0; j < edges[course].size(); ++j){
                    --degrees[edges[course][j]];
                    if(degrees[edges[course][j]] == 0) q.push(edges[course][j]);
                }
            }
        }
        // if there is cycle then the number would not equal to numCourses
        if(ans.size() != numCourses) return vector<int>();
        return ans;
    }
};
