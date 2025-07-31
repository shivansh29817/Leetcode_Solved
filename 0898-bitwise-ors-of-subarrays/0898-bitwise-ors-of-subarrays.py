class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        subsets: set[int] = {0}
        output: set[int] = set()
        for num in arr:
            subsets = {or_ | num for or_ in subsets} | {num}
            output |= subsets
        return len(output)