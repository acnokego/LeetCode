class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int>one_idx;
        vector<int>zero_len; // record the length of zero subarrays
        for(int i = 0; i < A.size(); ++i){
            if(A[i] == 1){
                if(one_idx.size()){
                    zero_len.push_back(i - one_idx.back() - 1);
                } else{
                    zero_len.push_back(i);
                }
                one_idx.push_back(i);
            }
        }
        int n = A.size();
        // for zero S,
        if(S == 0){            
            if(one_idx.size() == 0){
                return n*n - n * (n-1) / 2;
            } else {
                zero_len.push_back(n - one_idx.back() - 1);
                int zero_ans = 0;
                for(int i = 0; i < zero_len.size(); ++i){
                    int len = zero_len[i];
                    zero_ans += len*len - len * (len - 1) / 2;
                }
                return zero_ans;
            }
        }
        
        int prev_idx = -1;
        int ans = 0;
        for(int i = 0; (i + S - 1) < one_idx.size(); ++i){
            int start_idx = one_idx[i];
            int end_idx = one_idx[i+S-1];
            // zero in the beginning of subarray, one in the end
            ans += (one_idx[i] - prev_idx - 1);
            // one in the beginning and end of the array
            ans += 1;
            if((i + S) < one_idx.size()){
                // one in the beginning, zero in the end of the array
                ans += (one_idx[i+S] - end_idx - 1);
                //zero in the beginning and end of the array
                ans += (one_idx[i] - prev_idx - 1) * (one_idx[i+S] - end_idx - 1);
            } else {
                // one in the beginning, zero in the end of the array
                ans += (n - end_idx - 1);
                //zero in the beginning and end of the array
                ans += (one_idx[i] - prev_idx - 1) * (n - end_idx - 1);
            }
           
            prev_idx = start_idx;
        }
        return ans;
    }
};
