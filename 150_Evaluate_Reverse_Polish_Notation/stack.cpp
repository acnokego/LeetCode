class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    int evalRPN(vector<string>& tokens) {
        vector<int>operands;
        unordered_set<string>operators{"+", "-", "*", "/"};
        for(int i = 0; i < tokens.size(); ++i){
            if(operators.count(tokens[i]) && operands.size() >= 2){
                int op2 = operands.back();
                operands.pop_back();
                int op1 = operands.back();
                operands.pop_back();
                if (tokens[i] == "+"){
                    operands.push_back(op1 + op2);
                } else if (tokens[i] == "-"){
                    operands.push_back(op1 - op2);
                } else if (tokens[i] == "*"){
                    operands.push_back(op1 * op2);
                } else {
                    operands.push_back(op1 / op2);
                }
            } else {
                operands.push_back(stoi(tokens[i]));
            }
        }
        return operands[0];
    }
};
