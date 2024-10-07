class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = ['' for _ in range(min(numRows, len(s)))]
        reverse = False
        index = 0
        for char in s:
            rows[index] += char
            if reverse:
                index -= 1
            else:
                index += 1
            if index == 0 or index == numRows - 1:
                reverse = not reverse
        return ''.join(rows)