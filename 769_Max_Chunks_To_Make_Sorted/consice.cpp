class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int s = arr.size();
        if(s){
            // the maximum number we see now
            int max = -1;
            for(int i = 0; i < s; ++i){
                max = (arr[i] > max) ? arr[i] : max;
                // if the number <= smaller number in this chunk now.
                if(max == i) ans += 1;
            }
        }
        return ans;
        
    }
};
