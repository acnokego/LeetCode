class Solution {
  /*
   * Complexity: O(32n)
   * Space: O(n)
   */
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int max = 0;
        // start from the MSB, to look for the 
        // possible XOR results for the bits
        for(int i = 31; i >=0; --i){
            mask = mask | (1 << i);
            unordered_set<int>prefixes;
            // get the prefix of each number
            // MS 32 - i bits
            for(auto n : nums){
                prefixes.insert(n & mask);
            }
            // previous max + 1
            int potential_max = max | (1 << i);
            for(auto it = prefixes.begin(); it != prefixes.end(); ++it){
                // there is two prefixes can have result of potential max
                if(prefixes.count(*it ^ potential_max)){
                    max = potential_max;
                    break;
                }
            }
            
        }
        return max;
    }
};
