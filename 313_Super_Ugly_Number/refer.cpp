class Solution {
  /*
   * Complexity: O(nk)
   * Space: O(n+k)
   */
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>last_min(primes.size());
        vector<int>uglys(n, INT_MAX);
        
        uglys[0] = 1;
        
        // the nth ugly number must be the product 
        // of primes and the previous ugly number
        for(int i = 1; i < n; ++i){
            // for each prime, record the last ugly it used
            // to avoid repeated used. Since each time we would like
            // to find a ugly that is bigger than the previous ugly.
            for(int j = 0; j < primes.size(); ++j){
                uglys[i] = min(uglys[i], primes[j] * uglys[last_min[j]]);
            }
            
            // update the ugly index of each prime to make sure that
            // next time each prime * its corresponding ugly would be
            // bigger than the current ugly.
            for(int j = 0; j < primes.size(); ++j){
                while (primes[j] * uglys[last_min[j]] <= uglys[i]) last_min[j]++;
            }
        }
        return uglys.back();
    }
};
