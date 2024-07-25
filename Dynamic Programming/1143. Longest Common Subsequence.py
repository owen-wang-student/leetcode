class Solution:
    def helper(self, i1: int, s1: str, i2: int, s2: str, dp) -> int:
        if i1 >= len(s1) or i2 >= len(s2):
            return 0

        if dp[i1][i2] != -1:
            return dp[i1][i2]

        if s1[i1] == s2[i2]:
            ans = 1 + self.helper(i1 + 1, s1, i2 + 1, s2, dp)
            dp[i1][i2] = ans
            return ans
        else:
            ans = max(self.helper(i1 + 1, s1, i2, s2, dp), self.helper(i1, s1, i2 + 1, s2, dp))
            dp[i1][i2] = ans
            return ans


    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1] * len(text2) for i in range(len(text1))]
        return self.helper(0, text1, 0, text2, dp)