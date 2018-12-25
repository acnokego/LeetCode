class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */ 
public:
    string getPermutation(int n, int k) {
        
        if(!n) return string();
        
        vector<int>factorial(n + 1);
        
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i){
            factorial[i] = factorial[i-1] * i;
        }
        
        vector<char>number_left(n);
        for(int i = 0; i < n; ++i){
            number_left[i] = (char)('0' + i + 1);
        }
        
        string ans;
        --k;

        // For each char in number left as the first character, there would be
        // (i-1)! possible permutations. The index indicate the index of character we have
        // to append now. After appending it, we remove the character from
        // number_left. 
        for(int i = n; i >= 1; --i){
            int index = k / factorial[i-1];
            ans += number_left[index];
            number_left.erase(number_left.begin() + index);
            k = k % factorial[i-1];
        }
            
            
        return ans;
    }
};
