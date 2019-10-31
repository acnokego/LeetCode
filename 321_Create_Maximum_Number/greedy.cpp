class Solution {
public:
    // O(len)
    vector<int>maxArray(vector<int>& arr, int len){
        vector<int>ans;
        int num_to_drop = arr.size() - len;
        for(int num : arr){
            while(num_to_drop && ans.size() && ans.back() < num){
                ans.pop_back();
                --num_to_drop;
            }
            ans.push_back(num);
        }
        ans.resize(len);
        return ans;
    }
    // O(k * min(m, n))
    vector<int>merge(vector<int> arr1, vector<int> arr2){
        int l1 = arr1.size(), l2 = arr2.size();
        vector<int>merge_arr(l1 + l2);
        for(int i = 0, j = 0, r = 0; r < (l1 + l2); ++r){
            merge_arr[r] = greater(arr1, i, arr2, j) ? arr1[i++] : arr2[j++];
        }
        return merge_arr;
    }
    bool greater(vector<int>& new_arr, int ptr1, vector<int>& ori_arr, int ptr2){
        int new_l = new_arr.size(), ori_l = ori_arr.size();
        // find the first integer that doesn't match and use the greater one.
        while(ptr1 < new_l && ptr2 < ori_l && new_arr[ptr1] == ori_arr[ptr2]){
            ++ptr1;
            ++ptr2;
        }
        // ptr1 is longer, so new_arr is bigger than ori_arr
        // or there is a number different in the array
        return ptr2 == ori_l || (ptr1 < new_l && new_arr[ptr1] > ori_arr[ptr2]); 
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>ans;
        int n1 = nums1.size(), n2 = nums2.size();
        // O(k * (k * min(m,n) + k))
        // O((m+n)^3)
        for(int i = max(k - n2, 0); i <= min(k, n1); ++i){
            vector<int>tmp = merge(maxArray(nums1, i), maxArray(nums2, k-i));
            if(greater(tmp, 0, ans, 0)){
                ans = tmp;
            }
        }
        return ans;
    }
};
