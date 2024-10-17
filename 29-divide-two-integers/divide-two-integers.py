class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        else:
            division = dividend/divisor
            if division > 0:
                return floor(division)
            return ceil(division)


        