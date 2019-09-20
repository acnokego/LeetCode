class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(n)
     *
     * Similar to Checking if a number is a prime 
     */
    int minSteps(int n) {
        
        int num_op = 0;
        if(n <= 1) return 0;

        vector<int>op(n+1);
        op[1] = 1;
        
        for(int i = 2; i <=n; ++i){
            if(!op[i]) {
                op[i] = i; // can only be decomposed to 1
            }
            for(int j = 2; i*j <= n; ++j){
                // op[i] + 1 (copy_all) + (j-1) paste
                op[i*j] = (op[i*j] == 0) ? (op[i] + j) : min(op[i] + j, op[i*j]);
            }
        }
        return  op[n];
    }
};
