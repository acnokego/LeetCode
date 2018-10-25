class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int s = arr.size();
        if(s){
            // the number to search for starting the next chunk
            int include = 0;
            // the maximum number we see now
            int max = -1;
            for(int i = 0; i < s; ++i){
                max = (arr[i] > max) ? arr[i] : max;
                if(arr[i] > include)continue;
                // find the number to start the chunk
                else if(arr[i] == include){   
                    // make sure all the number <= max is in the chunk
                    if(max - i == 0) ans += 1;
                    // find next start number
                    // can keep finding without increasing ans
                    // since there is a number missing
                    include = max + 1;
                }
                // if not all the number <= previous max in this chunk
                else if(arr[i] < include){
                    // if the total number is correct add this chunk to ans.
                    if(i - (include - 1) == 0){
                        ans += 1;
                    }
                }
            }
            
        }
        return ans;
        
    }
};
