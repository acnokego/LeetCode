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
        int start = node -> label;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode* clone = new UndirectedGraphNode(node -> label);
        get_ptr[node -> label] = clone;
        q.push(node);
        while(!q.empty()){
            node = q.front();
            q.pop();
            clone = get_ptr[node -> label];
            for(int i = 0; i < node -> neighbors.size(); ++i){
                if(!get_ptr.count(node -> neighbors[i] -> label)){
                    UndirectedGraphNode* copy = new UndirectedGraphNode(node -> neighbors[i] -> label);
                    get_ptr[node -> neighbors[i] -> label] = copy;
                    // build each node once
                    q.push(node -> neighbors[i]);
                }
                clone -> neighbors.push_back(get_ptr[node->neighbors[i]->label]);
                
            }
            
        }
        return get_ptr[start];
    }
};


