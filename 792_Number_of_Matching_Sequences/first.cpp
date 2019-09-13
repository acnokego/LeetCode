class Solution {
public:
    /*
     * Complexity: O(n*lg(m)) total number of chars in words.
     * Space: O(1) // only alphabet
     */
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int>>occur_idx;
        for(int i = 0; i < S.length(); ++i){
           occur_idx[S[i]].push_back(i);
        }
        
        int ans = 0;
        for(string& word : words){
            int prev_end = -1;
            bool match = true;
            for(auto & ch : word){
                if(!occur_idx.count(ch)){
                    match = false;
                    break;
                }
                else{
                    // check if one of the idx of this character is bigger the previous one
                    auto it = lower_bound(occur_idx[ch].begin(), occur_idx[ch].end(), prev_end + 1);            
                    if(it != occur_idx[ch].end()){
                        prev_end = *it;
                    } else{
                        match = false;
                        break;
                    }
                }
            }
            if(match) ans += 1;
        }
        return ans;
    }
};
