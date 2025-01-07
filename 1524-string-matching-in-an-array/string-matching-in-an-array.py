# I used Chatgpt to convert My cpp code into python 
class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False
        self.count = 0

    def is_present(self, c):
        return self.children[ord(c) - ord('a')] is not None

    def insert(self, c):
        self.children[ord(c) - ord('a')] = TrieNode()

    def get_next(self, c):
        return self.children[ord(c) - ord('a')]

    def set_end(self, flag):
        self.isEnd = flag


class Solution:
    def __init__(self):
        self.root = TrieNode()

    def stringMatching(self, words):
        for word in words:
            for i in range(len(word)):
                suffix = word[i:]
                self.insert_in_trie(suffix)
        
        ans = []
        for word in words:
            if self.search_in_trie(word):
                ans.append(word)
        
        return ans

    def insert_in_trie(self, s):
        curr = self.root
        for c in s:
            if not curr.is_present(c):
                curr.insert(c)
                curr.count += 1
            curr = curr.get_next(c)
        curr.set_end(True)
        curr.count += 1

    def search_in_trie(self, s):
        curr = self.root
        for c in s:
            curr = curr.get_next(c)
        if curr.count > 1:
            return True
        return False