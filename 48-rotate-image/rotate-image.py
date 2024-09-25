class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)
        for x in range(n):
            for y in range(x+1,n):
                matrix[x][y],matrix[y][x] = matrix[y][x],matrix[x][y]

        for z in range(n):
            matrix[z].reverse()
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        