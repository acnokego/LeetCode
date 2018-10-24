class Solution {
  /*
   * Complexity: O(l*|d|)
   * Space: O(1)
   */
public:
    bool common_sub(string s1, string s2){
        string ans;
        if(s2.length() > s1.length()) return false;
        int pos_s1 = 0, pos_s2 = 0;
        while(pos_s2 <= s2.length() - 1 && pos_s1 <= s1.length()-1){
            if(s2[pos_s2] == s1[pos_s1]){
                ++pos_s1;
                ++pos_s2;
            }
            else ++pos_s1;
        }
        return (pos_s2 == s2.length());
    }
    string findLongestWord(string s, vector<string>& d) {
        int max_length = 0;
        string ans;
        int l = d.size();
        if(l){
            for(int i = 0; i < l; ++i){
                //if the common of d[i] and s is d[i]
                if(common_sub(s,d[i]) && d[i].length()){
                    if(d[i].length() > max_length){
                        ans = d[i];
                        max_length = d[i].length();
                    }
                    else if (d[i].length() == max_length){
                        ans = (ans < d[i]) ? ans : d[i];
                    }
                }
            }
        }
        return ans;
    }
};
