class Solution {
public:
    int minDistance(string word1, string word2) {
        int i1 = word1.size();
        int i2 = word2.size();
        int dp[i1+1][i2+1];

        for(int i = 0; i < i1+1; i++){
            for(int j = 0; j < i2+1; j++){
                if(i == 0){
                    dp[i][j] = j;
                }else if(j == 0){
                    dp[i][j] = i;
                }else if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }

        return dp[i1][i2]; 
    }
};