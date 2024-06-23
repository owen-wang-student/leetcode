// Binary Search 
// Time Complexity O(log(n))
// Space Complexity O(1)

class Solution {
    public:
        int firstIndex(vector<int>& nums, int target){
            int start = 0; 
            int end = nums.size() -1; 
            int ret = -1;

            while(start <= end){
                int mid = (start + end)/2;
                if(nums[mid] == target){
                    ret = mid; 
                    end  = mid - 1; //continue checking left 
                }else if(nums[mid] < target){
                    start = mid + 1; 
                }else {
                    end = mid - 1;
                }
            }
            return ret; 
        }
        
        int lastIndex(vector<int>& nums, int target, int start){
            if(start == -1){
                return -1; 
            }
            while(start < nums.size()){
                if(nums[start] != target){
                    return start - 1; 
                }
                start ++; 
            }
            return start - 1; 
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            int s = firstIndex(nums, target);
            int e = lastIndex(nums, target, s);
            ans.push_back(s);
            ans.push_back(e);
            return ans;
        }
};