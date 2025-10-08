class Solution:
    def successfulPairs(self, a: List[int], b: List[int], q: int) -> List[int]:
        b.sort()
        return [len(b)-bisect_left(b,q/v) for v in a]