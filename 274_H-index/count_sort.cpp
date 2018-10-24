class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(n)
   */
public:
    int hIndex(vector<int>& citations) {
        int s = citations.size();
        if(!s) return 0;
        vector<int>counter(s+1);
        // store the count of each number of citations.
        // it the number is bigger than s store it in s as well
        for(int i = 0; i < citations.size(); ++i){
            if(citations[i] >= s)
                counter[s] += 1;
            else
                counter[citations[i]] += 1;
        }
        int count = 0;
        // check if the total number of citations larget than i is bigger than 
        // the i (the possible h_index).
        for(int i = s; i >= 0; --i){
            count += counter[i];
            if(count >= i) return i;
        }
        return 0;
    }
};
