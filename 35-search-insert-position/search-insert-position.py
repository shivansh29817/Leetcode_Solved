class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        elif max(nums)<target:
            return len(nums)
        for i in nums:
            if i>target:
                return nums.index(i)