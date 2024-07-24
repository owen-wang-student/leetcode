class Solution {
public:
    void helper(unordered_map<int, int>& mem, vector<int>& cost, int index){
        if(index >= cost.size()){
            return;
        }
        mem[index] = min(mem[index-1] + cost[index], mem[index-2] + cost[index]); 
        helper(mem, cost, index+1);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> mem;
        mem[0] = cost[0];
        mem[1] = cost[1];
        helper(mem, cost, 2);
        return min(mem[cost.size()-1], mem[cost.size()-2]);
    }
};