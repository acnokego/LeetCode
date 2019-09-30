class Solution {
public:
    /*
     * Complexity: O(N)
     * Space: O(N)
     */
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int size = row.size();
        
        vector<int>partner(size); // map the index to the index of its partner
        vector<int>pos(size); // the index position of the specific element
        
        for(int i = 0; i < size; ++i){
            partner[i] = (i % 2 == 0) ? i + 1 : i - 1;
            pos[row[i]] = i;
        }
        
        for(int i = 0; i < size; ++i){
            for(int j = partner[pos[partner[row[i]]]]; i != j; j = partner[pos[partner[row[i]]]]) {
                // j would be the seat the row[i] need to be moved to
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]); // change the element's index
                ++ans;
                // next iteration j would be the element that get swapped with i in the current iter
            }
        }
        return ans;
    }
};
