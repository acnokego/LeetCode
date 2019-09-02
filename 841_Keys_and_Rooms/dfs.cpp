class Solution {
public:
    /*
     * Complexity: O(V+E)
     * Space: O(V)
     */
    void dfs(bool& ans, int room, const vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[room] = true;
        // no false
        if(find(visited.begin(), visited.end(), false) == visited.end()){
            ans = true;
            return;
        }
        for(int key : rooms[room]) {
            if(!visited[key]){
                dfs(ans, key, rooms, visited);
            }
            // able to go to every room
            if(ans) return;
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(!rooms.size()) return false;
        vector<bool>visited(rooms.size(), false);
        bool ans = false;
        dfs(ans, 0, rooms, visited);
        return ans;
    }
};
