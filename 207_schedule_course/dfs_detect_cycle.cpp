class Solution {
  /*
   * Complexity: O(V + E) // traversal through each edge and check each node.
   * Space: O(E) stacks
   */
public:
    bool dfs(vector<vector<int>>& edges, vector<bool>& visited, int start, vector<bool>& check){
        check[start] = true;
        if(visited[start]) return false;
        visited[start] = 1;
        for(auto& v: edges[start]){
            bool tmp_ans =  dfs(edges, visited, v, check);
            if(!tmp_ans) return false;
        }
        // the recursion stack of this path is end
        visited[start] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > edges (numCourses);
        for(auto& p : prerequisites){
            edges[p.second].push_back(p.first);
        }
        // see if this vertex has been checked in previous traversal (use the vertex as the start point)
        vector<bool>check(numCourses, false);
        for(int i = 0 ; i < numCourses; ++i){
            vector<bool>visited(numCourses, 0);
            if(!check[i]){
                bool tmp_ans = dfs(edges, visited, i, check);
                if(!tmp_ans) return false;
            }
        }
        return true;
    }
};
