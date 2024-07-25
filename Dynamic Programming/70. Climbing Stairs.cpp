class Solution {
public:
    void helper(int index, int n, unordered_map<int, int>& mem){
        if(index > n){
            return;
        }
        mem[index] = mem[index-1] + mem[index-2]; 
        helper(index+1, n, mem);
    }

    int climbStairs(int n) {
        unordered_map<int, int> mem; 
        mem[1] = 1;
        mem[2] = 2; 
        helper(3, n, mem);
        return mem[n];
    }
};