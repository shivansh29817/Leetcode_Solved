class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        candidates = set()
        
        # Edge cases: for n = "1", nearest palindrome is "0".
        if n == "1":
            return "0"
        
        
        prefix = n[:(length + 1) // 2]
        prefix_number = int(prefix)
        
        # Generate the candidates
        for i in [-1, 0, 1]:
            # Adjust the prefix and create the palindrome
            new_prefix = str(prefix_number + i)
            if length % 2 == 0:
                candidate = new_prefix + new_prefix[::-1]
            else:
                candidate = new_prefix + new_prefix[:-1][::-1]
            candidates.add(candidate)
        
        
        candidates.add(str(10**(length-1) - 1))
        candidates.add(str(10**length + 1))
        
        # Remove the original number from the candidates set
        candidates.discard(n)
        
        # Find the closest palindrome by comparing the absolute difference
        closest_palindrome = min(candidates, key=lambda x: (abs(int(x) - int(n)), int(x)))
        
        return closest_palindrome