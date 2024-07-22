class Solution {
public:

    void helper(unordered_map<int, int>& mem, int index, int max_index, vector<int> nums){
        if(index > max_index){
            return; 
        }
        int max_behind = 0; 
        for(int i = 0; i < index-1; i++){
            if(mem[i] > max_behind){
                max_behind = mem[i];
            }
        }
        cout << max_behind;
        mem[index] = max(mem[index], nums[index] + max_behind);
        helper(mem, index+1, max_index, nums);
    }

    int rob(vector<int>& nums) {
        unordered_map<int, int> mem; 
        mem[0] = nums[0];
        if(nums.size() > 1){
            mem[1] = nums[1];
        }
        helper(mem, 2, nums.size()-1, nums);

        if(nums.size() >= 2){
            return max(mem[nums.size()-1], mem[nums.size()-2]);
        }else{
            return mem[nums.size()-1];
        }
    }
};