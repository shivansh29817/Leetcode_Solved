class Solution:
    def maximumEnergy(self, energy: list[int], k: int) -> int:
        n = len(energy)
        ans = float('-inf')
        for i in range(n - 1, n - k - 1, -1):
            sum_ = 0
            j = i
            while j >= 0:
                sum_ += energy[j]
                ans = max(ans, sum_)
                j -= k
        return ans
        