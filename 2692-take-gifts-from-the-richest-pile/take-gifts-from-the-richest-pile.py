from typing import List
import heapq

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # Create a max-heap using negative values since Python's heapq is a min-heap by default
        max_heap = [-gift for gift in gifts]
        heapq.heapify(max_heap)
        
        total_value = sum(gifts)  # Calculate the initial total value of gifts
        
        for _ in range(k):
            # Get the largest gift (remember to negate back to positive)
            largest_gift = -heapq.heappop(max_heap)
            # Calculate the new value after taking the square root
            new_value = int(largest_gift ** 0.5)
            # Update the total value
            total_value -= (largest_gift - new_value)
            # Push the new value back into the heap
            heapq.heappush(max_heap, -new_value)
        
        return total_value