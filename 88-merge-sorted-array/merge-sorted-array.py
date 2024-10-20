class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1  # Pointer for nums1
        p2 = n - 1  # Pointer for nums2

        for p in range(n + m - 1, -1, -1):
            if p2 < 0:
                break  # No more elements in nums2 to merge

            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1  # Move pointer in nums1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1  # Move pointer in nums2