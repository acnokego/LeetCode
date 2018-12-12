class Solution {
  /*
   * Complexity: O(n)
   *
   * Explain (leetcode.com/problems/daily-temperatures/discuss/121787/C++-Clean-code-with-explanation:-O(n)-time-and-O(1)-space-(beats-99.13)/169785)
   * The worst case one might construct is such:[ 30 , 29 ,1,2,3, 4,5,31]
   * The patial answer will be [ ?, ? , 1,1,1,1,1,0]
   * For 29, to figure out 31>29, you have to nearly go though the whole list.
   * The benefit is for 30, you just need to check 29->31. you do not need to go 
   * through the whole loop again. That is why it is not O(N^2).
   *
   * Space: O(1)
   */
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int>ans(n);
        
        // traverse from the back
        for(int i = n - 2; i >= 0; --i){
            int j = i + 1;
            
            // if the next day is colder
            while(j < n && T[j] <= T[i]){
                // find the index that is warmer
                // moving index to the next one that is warmer than j
                if(ans[j] != 0) j += ans[j];
                // if we cannot find 
                else j = n;
            }
            
            if(j < n) ans[i] = j - i;
        }
        
        return ans;
    }
};
