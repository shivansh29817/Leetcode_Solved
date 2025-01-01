class Solution:
    def maxScore(self, s: str) -> int:
        ans, zeros, ones = 0, 0, s.count('1')
        
        for i in range(len(s) - 1):
            zeros += s[i] == '0'
            ones -= s[i] == '1'
            ans = max(ans, zeros + ones)
        return ans