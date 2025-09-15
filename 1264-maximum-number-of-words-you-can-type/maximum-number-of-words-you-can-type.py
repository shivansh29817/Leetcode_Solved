class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        text = text.split()
        
        count = 0

        for word in text:

            for ch in brokenLetters:

                if ch in word:
                    break
            
            else:
                count += 1

        return count