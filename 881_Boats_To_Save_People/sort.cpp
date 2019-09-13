class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(1)
     *
     * Want the total number of boats to be the minimum -> see if the person of
     * the min w and the person of max w can fit in the boat. If not, fit the
     * max w person.
     */
    int numRescueBoats(vector<int>& people, int limit) {
        int total_num = 0;
        sort(people.begin(), people.end());
        
        int size = people.size();
        int start = 0;
        int end = size - 1;
        
        while(start < end){
            if(people[start] > limit) return total_num;
            int curr_sum = people[start] + people[end];
            if(curr_sum <= limit){      
                ++start;
                --end;
                ++total_num;
            } else if(people[end] <= limit){
                --end;
                ++total_num;
            }
            
        }
        
        if(start == end && people[start] <= limit){
            ++total_num;
        }
        return total_num;
    }
};
