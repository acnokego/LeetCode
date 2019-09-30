class Solution {
public:
    /*
     * Complexity: O(2^N)
     * Space: O(N)
     */
    void recursive(vector<int>&tmp_ans, string curr, int N, int K){
        if(curr.length() == N){
            tmp_ans.push_back(stoi(curr));
            return;
        }
        if(curr == "0" && N != 1){
            return;
        }
        if (curr.back() - '0' - K >= 0){
            string append = to_string(curr.back() - '0' - K);
            recursive(tmp_ans, curr + append, N, K);
        }
        if ( K != 0 && curr.back() - '0' + K <= 9){
            string append = to_string(curr.back() - '0' + K);
            recursive(tmp_ans, curr + append, N, K);
        }
        
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int>ans;
        
        for(int i = 0; i <= 9; ++i){
            string start = to_string(i);
            vector<int>tmp_ans;
            recursive(tmp_ans, start, N, K);
            ans.insert(ans.end(), tmp_ans.begin(), tmp_ans.end());
        }
        return ans;
    }
   
};
