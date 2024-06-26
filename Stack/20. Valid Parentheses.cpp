class Solution {
public:
    bool isValid(string s) {
        stack<char> stack; 

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c); 
            }else{
                if(stack.empty()){
                    return false; 
                }else if(c == ')' && stack.top() == '('){
                    stack.pop();
                }else if(c == ']' && stack.top() == '['){
                    stack.pop();
                }else if(c == '}' && stack.top() == '{'){
                    stack.pop();
                }else{
                    return false; 
                }
            }
        }
        if(stack.empty()){
            return true;
        }else{
            return false; 
        }
    }
};