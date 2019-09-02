class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1) there will be only lower english alphabetical characters.
     *
     * Since we want the partition be as many as possible, the greedy method is
     * applied, requirements: each letters appears in at most one part. 
     * 1. first get the last index of occurrence of each char.
     * 2. get the end of current possible partitions (using the requirements)
     * by updating the end with the last
     * index of occurrence of letters.
     * 3. The greedy part here is that we cut the current partition when the
     * current pointer reaches the end of the current partition (the shortest
     * partition we can have given the requirements).
     */
    vector<int> partitionLabels(string S) {
        vector<int>last_occur(26);
        vector<int>ans;
        
        int l = S.length();
        if(!l) return ans;

        for(int i = 0; i < l; ++i) {
            last_occur[S[i] - 'a'] = i;
        }
        
        
        int start = 0;
        int longest = 0; // the end of the current partition
        for(int i = 0; i < l; ++i){
            longest = (last_occur[S[i] - 'a'] > longest) ? last_occur[S[i] - 'a'] : longest;
            // get the current partition
            if(i == longest) {
                ans.push_back(i-start+1);
                start = i + 1;
            }
        }
        return ans;
    }
};
