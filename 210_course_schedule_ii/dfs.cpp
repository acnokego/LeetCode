class Solution {
  /*
   * Complexity: O(V+E)
   * Space: O(E)
   */
public:
    bool dfs(vector<vector<int>>& edges, vector<bool>&visited, vector<bool>& onpath, int start, vector<int>& ans){
        if(visited[start]) return true;
        visited[start] = onpath[start] = true;
       
        for(auto& e : edges[start]){
            if(onpath[e] || !dfs(edges, visited, onpath, e, ans)){              
                // if we can find a cycle
                return false;
            }
        }
        // the courses need to meet all the prerequisites
        // can only make sure that this prerequisite(start) is in front of the following course
        // there may be other prerequisites as well
        ans.push_back(start);
        onpath[start] = false;
        return true;       
        
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        // get adjacent list
        for(auto& p : prerequisites){
            edges[p.second].push_back(p.first);
        }
    
 
       
        vector<int>ans;
        vector<bool>visited(numCourses, false);
        vector<bool>onpath(numCourses, false);
        for(int i = 0; i < numCourses; ++i){
            if(!visited[i] && !dfs(edges, visited, onpath, i, ans)) return vector<int>();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
