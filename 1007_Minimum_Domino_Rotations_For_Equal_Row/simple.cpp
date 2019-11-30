class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int v_1 = A[0], v_2 = B[0];
        int v_1_at_A = 0, v_1_at_B = 0;
        int v_2_at_B = 0, v_2_at_A = 0;
        
        bool no_v1 = false, no_v2 = false;
        for(int i = 0; i < A.size(); ++i){
            if(A[i] == v_1 && B[i] != v_1){
                v_1_at_A += 1;
            } else if(B[i] == v_1 && A[i] != v_1){
                v_1_at_B += 1;
            } else if(A[i] != v_1 && B[i] != v_1){
                no_v1 = true;
            } 
                      
                      
            if(A[i] == v_2 && B[i] != v_2){
                v_2_at_A += 1;
            } else if(B[i] == v_2 && A[i] != v_2){
                v_2_at_B += 1;
            } else if(A[i] != v_2 && B[i] != v_2){
                no_v2 = true;
            } 
            // one position doesn't have v1 and one position doesn't have v2
            // impossible to rotate
            if(no_v1 && no_v2){
                return -1;
            }
        }
        // if one of the position doesn't have v1, assign it to the maximum
        int v1_num = (no_v1) ? A.size() : min(v_1_at_B, v_1_at_A);
        int v2_num = (no_v2) ? A.size() : min(v_2_at_A, v_2_at_B);
                      
        return min(v1_num, v2_num);
        
    }
};
