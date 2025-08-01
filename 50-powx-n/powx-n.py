class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n==0: return float(1)
        if n<0:
            x = 1/x
            n = abs(n)
        if n%2==0:
            res = self.myPow(x, n//2)
            return res * res
        return x * self.myPow(x, n-1)