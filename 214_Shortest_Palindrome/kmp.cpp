class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    vector<int> buildKMPtable(string to_match){
        vector<int>table(to_match.length());
        int index = 0; // matched prefix index
        for(int i = 1; i < to_match.length(); ++i){
            if(to_match[index] == to_match[i]){
                table[i] = table[i-1] + 1;
                ++index;
            } else {
                 //by assigning index to table[i-1], we will shorten the match string length, and jump to the 
                //prefix part that we used to match postfix ended at i - 1
                index = table[i-1];
                
                // prefix[0...index-1] match postfix[...i-1]
            
                while(index > 0 && to_match[index] != to_match[i]){
                //shorten the matched prefix string until we revert to the beginning of match (index 1), since postfix == prefix, we can find it by iteration.
                // want to find if to_match[index] == to_match[i]
                
                    index = table[index-1];
                }
            
            //when we are here may either found a match char or we reach the boundary and still no luck
            //so we need check char match
                if(to_match[index] == to_match[i]){
                    //if match, then extend one char 
                    ++index;
                }
            
                table[i] = index;
            }
        }
        return table;
    }
    string shortestPalindrome(string s) {
        int len = s.length();
        string reverse_s(s);
        reverse(reverse_s.begin(), reverse_s.end());
        string to_match = s + "#" + reverse_s;
        vector<int>table = buildKMPtable(to_match);
        // find the maximum palid part in s starts from 0;
        string to_add = s.substr(table.back());
        reverse(to_add.begin(), to_add.end());
        return to_add + s;    
    }
};
