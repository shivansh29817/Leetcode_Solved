class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }

        # Define a recursive backtracking function
        def backtrack(i, currStr):
            # Base case: if the current combination has the same length as the input digits
            if len(currStr) == len(digits):
                # Add the current combination to the result
                res.append(currStr)
                return
            # Iterate through each character corresponding to the current digit
            for c in digitToChar[digits[i]]:
                
                backtrack(i + 1, currStr + c)

        
        if digits:
            backtrack(0, "")

        return res