class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(1)
   */
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        
        for(int& h : houses){
            int start = 0;
            int end = heaters.size() - 1;
            while(start < end){
                int mid = (start + end) / 2;
                if(heaters[mid] > h) end = mid;
                else if(heaters[mid] < h) start = mid;
                else{
                    break;
                }
                // two heaters left
                // find the one closest to the house
                // and see if the distance between them is under the coverage
                // if not, update the coverage
                if(start == end - 1){
                    int tmp_min = (abs(heaters[end] - h) < abs(heaters[start]-h)) ? 
                        abs(heaters[end] - h) : abs(heaters[start]-h);
                    ans = (tmp_min > ans) ? tmp_min : ans;
                    break;
                }
            }

            // for the case that there is only one heater
            if(start == end){
               ans = (abs(heaters[end] - h) > ans) ? abs(heaters[end] - h) : ans; 
            }
        }
        
        return ans;
        
    }
};
