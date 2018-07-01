class Solution {
/*
 * Complexity: O(4^n) n:number of digits
 * Space: O(4^n)
 * first store strings of map according to digits order in the vector "letters".
 * then run the loop from the last letter to the first letter. 
 * Append the possible chars to the front of the previous vectors of string.
 */
public:
    /*
     * a: the char needed to append to the front of b
     * b: possible letter combinations 
    */
    vector<string> append_combinations(string a, vector<string> b){
        vector<string>res;
        for(int i = 0; i < a.length(); ++i){
            for(int j = 0; j < b.size(); ++j){
                // Append the possible chars to the front of the previous vectors of string.
                res.push_back(a[i] + b[j]);
            }
        } 
        return res;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length() == 0) return ans;
        vector<string>letters;
        vector<string>map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.length(); ++i){
            letters.push_back(map[digits[i]-'0']);
        }
        for(int i = 0; i < letters.back().length(); ++i){
            ans.push_back(string(1, letters.back()[i]));
        }
        //then run the loop from the last letter to the first letter. 
        for(int i = letters.size()-1; i > 0; --i){
            ans = append_combinations(letters[i-1], ans);
        }
        return ans;
    }
};
