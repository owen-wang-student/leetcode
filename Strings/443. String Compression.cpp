class Solution {
public:
    int compress(vector<char>& chars) {
        int ret = 0; 
        int group_length = 0; 
        char group_char = ' ';
        int insert = 0; 

        for(int i = 0; i < chars.size(); i++){
            if(chars[i] != group_char){
                if(group_length == 1 && group_char != ' '){
                    chars[insert] = group_char;
                    insert += 1;
                    ret += 1;
                }else if(group_length > 1){
                    chars[insert] = group_char;
                    insert += 1;  
                    string s = to_string(group_length);
                    for(char c: s){
                        chars[insert] = c; 
                        insert += 1; 
                    }
                    ret += (1 + s.length());
                }
                group_length = 1;
                group_char = chars[i]; 
            }else{
                group_length += 1;
            }
        }

        if(group_length > 0){
           if(group_length == 1 && group_char != ' '){
                chars[insert] = group_char;
                insert += 1;
                ret += 1;
            }else if(group_length > 1){
                chars[insert] = group_char;
                insert += 1;  
                string s = to_string(group_length);
                for(char c: s){
                    chars[insert] = c; 
                    insert += 1; 
                }
                ret += (1 + s.length());
            }
        }

        return ret; 
    }
};