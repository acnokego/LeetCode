class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   * to much case to consider
   */
public:
    int maximumSwap(int num) {
        string num_s = to_string(num);
        bool swap = false;
        int start = 0;
        while(!swap && start < num_s.length()){
            char max_v = '0';
            int max_idx = start;
            // find the maximum
            for(int i = start; i < num_s.length(); ++i){
                // find the right-most index that has the maximum value
                if(num_s[i] >= max_v){
                    max_v = num_s[i];
                    max_idx = i;
                }
            }
            // if the maximum already in the right position
            // find the next maximum
            if(max_idx == start || num_s[max_idx] == num_s[start]){
                ++start;
            }
            else{
                char tmp = num_s[start];
                num_s[start] = num_s[max_idx];
                num_s[max_idx] = tmp;
                swap = true;
            }
        }
        return stoi(num_s);
    }
};
