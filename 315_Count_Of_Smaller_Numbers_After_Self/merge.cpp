class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(n)
     */
    void mergeSort(vector<int>& nums, vector<int>& index, int left, int right, vector<int>& ans){
        if(right <= left){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, index, left, mid, ans);
        mergeSort(nums, index, mid + 1, right, ans);
        merge(nums, index, left, right, ans);
    }
    
    void merge(vector<int>& nums, vector<int>& index, int start, int end, vector<int>& ans){
        int mid = start + (end - start) / 2;
        int left_idx = start;
        int right_idx = mid + 1;
        int rightcount = 0; //
        vector<int>new_idx(end - start + 1);
        
        int sort_idx = 0;
        // merge
        while(left_idx <= mid && right_idx <= end){
            //compare element between left and right
            if(nums[index[right_idx]] < nums[index[left_idx]]){
                new_idx[sort_idx] = index[right_idx];
                ++rightcount; // element in right be moved to left
                ++right_idx;
            } else {
                new_idx[sort_idx] = index[left_idx];
                ans[index[left_idx]] += rightcount; // number of elements in right be moved in front of the current left_idx
                ++left_idx;
            }
            ++sort_idx;
        }
        // push the rest element in left
	    while(left_idx <= mid){
		    new_idx[sort_idx] = index[left_idx];
		    ans[index[left_idx]] += rightcount;
		    ++left_idx;
		    ++sort_idx;
	    }
        // push the rest elements in right
        while(right_idx <= end){
		    new_idx[sort_idx++] = index[right_idx++];
	    }
        // update index
        for(int i = start; i <= end; ++i){
            index[i] = new_idx[i - start];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        vector<int>index; // the vector used to store the element's idx in original nums array, since the answer would use original idx.
        for(int i = 0; i < nums.size(); ++i){
            index.push_back(i);
        }
        mergeSort(nums, index, 0, nums.size() - 1, ans);
        return ans;
    }
};
