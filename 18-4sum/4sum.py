class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        rs = []
        
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n -2):
                left = j + 1
                right = n - 1
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                while right - left > 0:
                    sum = nums[i] + nums[j] + nums[left] + nums[right] 
                    if sum > target:
                        right -= 1
                    elif sum < target:
                        left += 1
                    else:
                        rs.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1

        return rs 