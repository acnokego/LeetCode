class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(sum == target){
                return vector<int>{start + 1, end + 1};
            } else if(sum < target){
                ++start;
                while(start < numbers.size() && numbers[start - 1] == numbers[start]) ++start;
            } else{
                --end;
                while(end >= 0 && numbers[end + 1] == numbers[end]) --end;
            }   
        }   
        return vector<int>();
    }
};
