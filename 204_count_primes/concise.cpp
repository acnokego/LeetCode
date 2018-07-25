class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool>isPrime(n, 1);
        int count = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                ++count;
                for(int j = 2; i*j < n; ++j){
                    isPrime[i*j] = 0;
                }
            }
        }
        return count;
    }
};
