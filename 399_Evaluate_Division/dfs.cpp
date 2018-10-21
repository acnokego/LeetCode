class Solution {
  /*
   * Complexity: O(q*(V+E)) n: the length of the relation of each query
   * Space: O(2 * #equations)
   *
   * Treat each variable as a node of a graph, saving this node in a hashmap.
   * Build the edge between nodes using equations (relation_edge). And use DFS
   * staring from the first variabl of q and end at the second variable to find
   * the path and the product of weights.
   */
public:
    typedef unordered_map<string, double> relation_edge;
       
    double dfs(string start, string end, unordered_map<string, relation_edge>& g, unordered_set<string>& visited) {
        visited.insert(start);
        auto edge = g.find(start);
        if(edge == g.end()) return -1;
        // next string
        auto next = edge -> second.find(end);
        // if a/a
        if(start == end) return 1.0;
        // if we there is only one edge between the end and start
        if(next != edge -> second.end()) return next -> second;
        // else use dfs to search the end
        double ans = -1.0;
        for(auto it = edge -> second.begin(); it != edge -> second.end(); ++it){
            if(visited.find(it->first) == visited.end() && (ans = dfs(it -> first, end, g, visited)) > 0)
                return ans * it -> second;
        } 
        return ans;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double>ans;
        unordered_map< string, relation_edge> relation_g ;
        // build graph 
        for(int i = 0; i < equations.size(); ++i) {
            if(relation_g.find(equations[i].first) != relation_g.end()) {
                relation_g[equations[i].first].insert({equations[i].second, values[i]});
            }
            else relation_g.insert({equations[i].first, relation_edge({{equations[i].second, values[i]}})});
            if(relation_g.find(equations[i].second) != relation_g.end()) {
                relation_g[equations[i].second].insert({equations[i].first, 1.0/values[i]});
            }
            else relation_g.insert({equations[i].second, relation_edge({{equations[i].first, 1.0/values[i]}})});
        }
        for(auto& q: queries) {
            unordered_set<string>visited;
            ans.push_back(dfs(q.first, q.second, relation_g, visited));
        }
        return ans;
    }
};
