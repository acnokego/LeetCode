class Solution {
  /*
   * Complexity: O(l)
   * Space: O(1)
   */
public:
    int findSubstringInWraproundString(string p) {
        int l = p.length();
        vector<int>count(26, 0);
        int ans = 0;
        
        int max_len = 0;
        for(int i = 0; i < l; ++i){
            
            // find the length of substring end at p[i]
            // it would be equal to the number of substring end at p[i]
            if( i > 0 && (p[i] == 'a' && p[i-1] == 'z') || p[i-1] == (p[i] - 1)){
                ++max_len;
            }
            else{
                max_len = 1;
            }
            
            // there would be multiple substrings in p end at p[i]
            count[p[i] - 'a'] = max(count[p[i] - 'a'], max_len);
            
        }
        
        for(int c : count){
            ans += c;
        }
        
        return ans;
        
    }
};
