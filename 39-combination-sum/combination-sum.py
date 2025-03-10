class Solution(object):
    def __init__(self):
        self.res = []
        self.path = []

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def backtracking(total,candidates,target,startIndex):
            if total == target:
                self.res.append(self.path[:])
                return
            # if total > target:
            #     return
            for i in range(startIndex,len(candidates)):
                if candidates[i] + total > target:
                    break
                total += candidates[i]
                self.path.append(candidates[i])
                backtracking(total,candidates,target,i)
                total -= candidates[i]
                self.path.pop()
        candidates.sort()  # sort Before backTracking
        backtracking(0,candidates,target,0)
        
        return self.res