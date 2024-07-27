class Solution {
public:
    string helper(int rcharge, int dcharge, int rcount, int dcount, queue<char>& q, string senate){
        cout << rcharge << dcharge << rcount << dcount << senate << endl; 
        for(char c: senate){
            if(rcharge == 0 && dcharge == 0){
                q.push(c);
                if(c == 'R') {
                    rcharge += 1;
                    rcount += 1;
                }
                if(c == 'D') {
                    dcharge += 1;
                    dcount += 1;
                } 
            }else if(rcharge > 0){
                if(c == 'R'){
                    rcharge += 1;
                    rcount += 1;
                    q.push(c);
                }
                if(c == 'D') {
                    rcharge -= 1;
                }
            }else if(dcharge > 0){
                if(c == 'D'){
                    dcharge += 1;
                    dcount += 1; 
                    q.push(c);
                }
                if(c == 'R') {
                    dcharge -= 1;
                } 
            }
        }

        if(rcount == 0 && dcount > 0){
            return "Dire";
        }else if(dcount == 0 && rcount > 0){
            return "Radiant";
        }else{
            queue<char> temp; 
            string s = "";
            while(!q.empty()){
                s += q.front();
                temp.push(q.front());
                q.pop();
            }
            return helper(rcharge, dcharge, 0, 0, q, s);
        }
    }

    string predictPartyVictory(string senate) {
        queue<char> q; 
        return helper(0, 0, 0, 0, q, senate); 
    }
};