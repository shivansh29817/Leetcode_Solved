
from bisect import bisect_left, bisect_right

class Solution:
    def maxTotalFruits(self, fruits, startPos, k):
        n = len(fruits)
        prefixSum = [0] * n
        indices = [0] * n

        for i in range(n):
            indices[i] = fruits[i][0]
            prefixSum[i] = fruits[i][1] + (prefixSum[i-1] if i > 0 else 0)

        maxFruits = 0

        for d in range(k // 2 + 1):
            remain = k - 2 * d
            i = startPos - d
            j = startPos + remain

            left = bisect_left(indices, i)
            right = bisect_right(indices, j) - 1

            if left <= right:
                total = prefixSum[right] - (prefixSum[left-1] if left > 0 else 0)
                maxFruits = max(maxFruits, total)

            i = startPos - remain
            j = startPos + d

            left = bisect_left(indices, i)
            right = bisect_right(indices, j) - 1

            if left <= right:
                total = prefixSum[right] - (prefixSum[left-1] if left > 0 else 0)
                maxFruits = max(maxFruits, total)

        return maxFruits
