class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if haystack == needle:
            return 0
        
        n, m = len(needle), len(haystack)
        hay = haystack[0:n]
        
        for i in range(n, m+1):
            if hay == needle:
                return i-n
            if i<m: hay = hay[1:] + haystack[i]
        
        return -1