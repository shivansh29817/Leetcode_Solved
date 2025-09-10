class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        i = 0
        j = 0
        o = []
        if len(nums) <0:
            return o
        if len(nums) ==1:
            return [str(nums[i])]
        while(j<len(nums)-1):
            if nums[j] +1 == nums[j+1]:
                j = j+1
            else:
                if i == j:
                    o.append(str(nums[i]))
                else:
                    o.append(str(nums[i]) + "->" +str(nums[j]))
                i = j+1
                j = i

        if i == j and j<len(nums):
            o.append(str(nums[i]))
        else:
            if  j<len(nums):
                o.append(str(nums[i]) + "->" +str(nums[j]))
        
        return o

        