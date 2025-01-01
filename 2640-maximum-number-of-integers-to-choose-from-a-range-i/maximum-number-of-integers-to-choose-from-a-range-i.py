class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        d=set(banned)
        sumi=0
        cnt=0
        for i in range(1,n+1):
            if i in d:
                continue
            if maxSum>=sumi+i:
                sumi+=i
                cnt+=1
        return cnt