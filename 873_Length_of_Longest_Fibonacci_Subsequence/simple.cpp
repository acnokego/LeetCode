class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        
        int ans = 0;
        int s = A.size();
        unordered_set<int>occur(A.begin(), A.end());
        
        for(int i = 0; i < s; ++i){
            for (int j = i + 1; j < s; ++j){
                int x_i = A[i], x_i1 = A[j], len = 2;
                while(occur.count(x_i + x_i1)){
                    int tmp = x_i;
                    x_i = x_i1;
                    x_i1 = tmp + x_i1;
                    ++len;
                }
                ans = max(len, ans);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
