class Solution {
public:
    /*
     * Complexity: O(101*101 + N)
     * Space: O(N)
     */
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long>num_count;
        for(int i = 0; i < A.size(); ++i){
            num_count[A[i]] += 1;
        }
        long count = 0;
        for(auto i = num_count.begin(); i != num_count.end(); ++i){
            for(auto j = num_count.begin(); j != num_count.end(); ++j){
                int k = target - i -> first - j -> first;
                if(!num_count.count(k)) continue;
                if(i -> first == j -> first && j -> first == k){
                    long occur = (i -> second * (i -> second - 1) * ( i -> second - 2) / 6);
                    count += occur;
                } else if (i -> first == j -> first && j -> first != k){
                    // for all tuple(i, j, k) that has two same member 
                    long occur = (i -> second * (i -> second - 1) / 2) * num_count[k];
                    count += occur;
                }
                // make sure we only calculate the count for i < j < k
                else if(i -> first < j -> first && j -> first < k) {
                    long occur = i -> second * j -> second * num_count[k];
                    count += occur;
                }
            }
        }
        return count % int(1e9 + 7);
    }
};
