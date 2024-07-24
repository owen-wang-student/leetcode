class Solution {
public:
    int countVowels(string sub){
        int count = 0; 
        for(char c: sub){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                count += 1;
            }
        }
        return count;
    }

    int maxVowels(string s, int k) {
        string sub = s.substr(0, k);
        int count = countVowels(sub);
        int max = count; 
        
        int start = 0; 
        int end = k-1; 

        for(char c: s.substr(k, s.length())){
            if(count > max){
                max = count; 
            }
            if(s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u'){
                count -= 1;
            }
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                count += 1;
            }
            start += 1; 
        }
        if(count > max){
            max = count; 
        }
        return max;
    }
};