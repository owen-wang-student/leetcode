class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack; 

        for(char c : s){
            if(stack.empty() || c != stack.top()){
                stack.push(c);
            }else{
                stack.pop();
            }
        }

        string ans = "";
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};