class Solution(object):
    def minScoreTriangulation(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        
        for l in range(2, n):
            for i in range(n - l):
                j = i + l
                dp[i][j] = float('inf')
                
                for k in range(i + 1, j):
                    cost = values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]
                    dp[i][j] = min(dp[i][j], cost)
        
        return dp[0][n - 1]