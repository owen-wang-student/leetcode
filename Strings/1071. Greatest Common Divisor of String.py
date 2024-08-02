class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:

        # get prefix
        gcd = ""
        for i in range(min(len(str1), len(str2))):
            if str1[i] == str2[i]:
                gcd += str1[i]
            else:
                break

        n = len(gcd)
        s1 = len(str1)
        s2 = len(str2)

        for i in range(n):
            if s1 % (n - i) == 0 and s2 % (n - i) == 0:
                sub = gcd[:n-i]
                if str1 == sub * (s1//(n-i)) and str2 == sub * (s2//(n-i)):
                    return sub

        return ""