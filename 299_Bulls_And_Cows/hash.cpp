class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    string getHint(string secret, string guess) {
        unordered_map<int, int>letter_count;
        for(char & c: secret){
            letter_count[c] += 1;
        }
        
        int num_A = 0;
        int num_B = 0;
        for(int i = 0; i < guess.length(); ++i) {
            if(guess[i] == secret[i]){
                ++num_A;
                letter_count[guess[i]] -= 1;
                if(letter_count[guess[i]] == 0){
                    letter_count.erase(guess[i]);
                }
            } 
        }
        for(int i = 0; i < guess.length(); ++i){
            if(guess[i] != secret[i] && letter_count[guess[i]]){
                ++num_B;
                letter_count[guess[i]] -= 1;
                if(letter_count[guess[i]] == 0){
                    letter_count.erase(guess[i]);
                }
            }
        }
        
        string ans;
        ans += to_string(num_A);
        ans += 'A';
        ans += to_string(num_B);
        ans += 'B';
        return ans;
    }
};
