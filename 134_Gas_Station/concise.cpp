class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(!gas.size()) return -1;
        int start = 0, gas_left = gas[0], total_gas = gas[0], total_cost = cost[0];
        
        for(int i = 0; i < (gas.size() - 1); ++i){
            if((gas_left - cost[i]) < 0){
                // reset
                gas_left = gas[i+1];
                start = i + 1;
            } else {
                gas_left = gas_left - cost[i] + gas[i+1];
            }
            total_gas += gas[i+1];
            total_cost += cost[i+1];
        }
        
        return (total_gas < total_cost) ? -1 : start;
        
    }
};
