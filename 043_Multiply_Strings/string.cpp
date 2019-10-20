class Solution {
public:
    /*
     * Complexity: O(l1*l2)
     * Space: O(l1+l2)
     */
    string multiply(string num1, string num2) {
        //unsigned long long ans = 0;
        int l1 = num1.length(), l2 = num2.length();
        string sum(l1 + l2, '0'); 
        for(int i = l1 - 1; i >= 0; --i){
            for(int j = l2 - 1; j >= 0; --j){
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                sum[i + j + 1] = tmp % 10 + '0';
                sum[i + j] += tmp / 10; // add carry bits  
            }
        }
        // remove the leading 0s
        for(int i = 0; i < sum.length(); ++i){
            if(sum[i] != '0'){
                return sum.substr(i);
            }
        }
        return "0";
    }
};
