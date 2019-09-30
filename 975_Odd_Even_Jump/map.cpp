class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(n)
     */
    int oddEvenJumps(vector<int>& A) {
        map<int, int>occur_idx;
        vector<bool>even(A.size(), false); // if we can reach the end when we do the even jump to the idx 
        vector<bool>odd(A.size(), false);
        
        occur_idx[A.back()] = A.size() - 1; // push the last element
        even.back() = true;
        odd.back() = true;
        int ans = 1;
        for(int i = A.size() - 2; i >= 0; --i){
            auto s_larger = occur_idx.lower_bound(A[i]); // the first one that >= A[i]
            auto l_smaller = occur_idx.upper_bound(A[i]); // the first one that is bigger than A[i], --l_smaller is the one that <= A[i]
            if(s_larger != occur_idx.end()){
                // if we can do odd jump depend on if we do even jump at s_larger->second
                odd[i] = even[s_larger -> second];
            }
            if(l_smaller != occur_idx.begin()){
                even[i] = odd[(--l_smaller) -> second];
            }
            if(odd[i]) ++ans;
            occur_idx[A[i]] = i;
        }
        return ans;
    }
};
