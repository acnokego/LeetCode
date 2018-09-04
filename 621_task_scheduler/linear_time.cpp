class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1) constant
   */
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26, 0);
        // we store the number of maximum occurrences of one task and the number of tasks has the maximum occurrences.
        int max_count = 0;
        int num_max = 0;
        for(auto & c : tasks){
            hash[c - 'A'] += 1;
            if(hash[c - 'A'] > max_count){
                max_count = hash[c - 'A'];
                num_max = 1;
            }
            else if(hash[c - 'A'] == max_count){
                ++num_max;
            }
        }
        int idle = 0;
        // if the char with the maximum count is 'A'
        // and the arrangement would be like ABXABXAB
        // part: we can separate the arragement with two part by A
        // part_length: the slot we need to filled in in each part
        int part = max_count - 1;
        int part_length = n - (num_max - 1);
        int emptyslot = part_length * part;
        int availableTask = tasks.size() - max_count * num_max;
        // if the emptyslot is less than available task, then we don't need to add idles
        idle = max(0, emptyslot - availableTask);
        return idle + tasks.size();
    }
};
