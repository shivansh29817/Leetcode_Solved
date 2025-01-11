class Solution:
    def wordSubsets(self, a: List[str], b: List[str]) -> List[str]:
        return (z:=reduce(or_,map(Counter,b))) and [s for s in a if Counter(s)>=z]