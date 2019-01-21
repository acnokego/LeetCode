class Solution {
  /*
   * Complexity: O(K*E)
   * Space: O(K*E)
   */
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        // bellman ford, the first index indicate the round of iteration, the
        // second index indicate the dst. each element would be the distance
        // from source to that node
        vector<vector<int>>distance(K+2, vector<int>(n, INT_MAX));
        
        distance[0][src] = 0;
        for(int i = 1; i <= K+1; ++i){
            distance[i][src] = 0;
            for(auto e : flights){
                if(distance[i-1][e[0]] != INT_MAX){
                    distance[i][e[1]] = min(distance[i][e[1]], distance[i-1][e[0]] + e[2]);
                }
                
            }
        }
        
        return (distance[K+1][dst] == INT_MAX) ? -1 : distance[K+1][dst];
    }
};
