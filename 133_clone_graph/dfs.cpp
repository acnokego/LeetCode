/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
 * Complexity: O(V+E)
 * Space: O(V)
 */
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*> get_ptr;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        if(!get_ptr.count(node -> label)){
            UndirectedGraphNode* clone = new UndirectedGraphNode(node -> label);
            get_ptr[node -> label] = clone;
            for(int i = 0; i < node -> neighbors.size(); ++i){
                clone -> neighbors.push_back(cloneGraph(node -> neighbors[i]));
            }
        }
        return get_ptr[node -> label];
    }
};


