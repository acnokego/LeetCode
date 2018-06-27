class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        int tmp;
        while(left != right){
            if(height[left] > height[right]){
                tmp = (right-left)*height[right];
                if(tmp > ans) ans = tmp;
                right -= 1;
            }
            else{
                tmp = (right-left)*height[left];
                if(tmp > ans) ans = tmp;
                left += 1;  
            }
        }
        return ans;
    }
};
