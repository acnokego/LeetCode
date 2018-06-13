class Solution {
public:
 /*
  * Complexity: O(n)
  * Space : O(n)
  * unordered_map == dict in python, insert, search , delete: O(1) average
  * map is implemented by red-black tree, insert, search, delete: O(log(n))
  */
    bool isValid(string s) {
        std::unordered_map<char,char> dict;
        dict[')'] = '(';
        dict[']'] = '[';
        dict['}'] = '{';
        std::vector<char>order;
        for(int i=0; i<s.length();++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                order.push_back(s[i]);
            }
            else if (dict.find(s[i]) != dict.end()){
                if (order.size() == 0 || order.back() != dict[s[i]]) return false;
                order.pop_back();
            }
        }
        if(order.size() == 0) return true; 
        else return false;
    }
};
