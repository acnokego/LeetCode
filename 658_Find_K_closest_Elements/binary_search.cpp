class Solution {
  /*
   * Complexity: O(lgn + k)
   * Space: O(1)
   */
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int start = 0, end = arr.size() - 1;
        int nearest;
        
        // binary search to find the ele that is the closest to x
        while(start < end){
            int mid = (start + end) / 2;
            if(arr[mid] > x) end = mid;
            else if (arr[mid] < x) start = mid;
            else {
                nearest = mid;
                break;
            }
            if(start == (end - 1)){
                if((x - arr[start]) < (arr[end] - x)){
                    nearest = start;
                }
                else{
                    nearest = end;
                }
                break;    
            }
        }
        if(start == end){
            nearest = start;
        }

        // the [left, right] are the intervals that
        // elements need to be returned as the ans;
        int right = nearest, left = nearest;
        while((right - left + 1) < k){
            int n_right =  right + 1;
            int n_left = left - 1;
            
            // to find if the right element is more closer
            // or the left. Then expand the interval to the
            // side that is closer.
            if(n_right < arr.size() && n_left >= 0){
                if(arr[n_right] - x < x - arr[n_left]){
                    right = n_right;
                }
                else{
                    left = n_left;
                }
            }
            else if(n_right < arr.size()){
                right = n_right;
            }
            else if(n_left >= 0){
                left = n_left;
            }
        }
        
        // push the elements in the interval
        for(int i = left; i <= right; ++i){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};
