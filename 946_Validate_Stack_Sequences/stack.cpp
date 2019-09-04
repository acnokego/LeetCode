class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int push_idx = 0, pop_idx = 0;
        int size = pushed.size();
        for(int p : pushed){
            s.push(p);
            while(pop_idx < size && s.size() && s.top() == popped[pop_idx]) {
                s.pop();
                ++pop_idx;
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};
