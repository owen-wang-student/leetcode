class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack; 

        for(string c: tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int n = stack.top();
                stack.pop();
                int m = stack.top();
                stack.pop();

                if(c == "+"){
                    stack.push(n+m);
                }else if(c == "-"){
                    stack.push(m-n);
                }else if(c == "*"){
                    stack.push(n*m);
                }else{
                    stack.push(m/n);
                }
            }else{
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};