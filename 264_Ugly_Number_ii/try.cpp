class Solution {
  /*
   * Complexity: O(ans) TLE
   * Space: O(n)
   */
public:
    int nthUglyNumber(int n) {
        
        unordered_set<int>ugly;
        unordered_set<int>primes({2, 3, 5});
        ugly.insert(1);
        
        int tmp_value = 2;
        while(ugly.size() < n){
            for(const int & p : primes){
                if(tmp_value % p == 0 && ugly.count(tmp_value/p)){
                    ugly.insert(tmp_value);
                    break;
                }
            }
                
            tmp_value++;          
        }
        
        return tmp_value - 1;
        
    }
};
