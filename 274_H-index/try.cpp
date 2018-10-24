class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(1)
   */
public:
    int hIndex(vector<int>& citations) {
        int s = citations.size();
        if(!s) return 0;
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for(int pos = 0; pos < citations.size(); ++pos){
            // if the number of citations bigger than citations[pos] is bigger than citations[pos]
            // the h_index would be citations[pos]
            // however, even if the number is smaller, the h_index could be citations.size()-pos
            // if it is bigger than the original h_index
            h_index = (citations.size() - pos >= citations[pos]) ? citations[pos] : 
            (h_index > citations.size() - pos) ? h_index : citations.size() - pos;
        }
        return h_index;
    }
};
