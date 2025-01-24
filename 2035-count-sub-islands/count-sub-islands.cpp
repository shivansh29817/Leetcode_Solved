class Solution {
private:
    vector<int> islandRoot;
    vector<char> islandStatus; // 0: unvisited, 1: valid sub-island, 2: invalid sub-island
    int numRows, numCols;

    int findIslandRoot(int x) {
        if (islandRoot[x] != x) {
            islandRoot[x] = findIslandRoot(islandRoot[x]); // Path compression
        }
        return islandRoot[x];
    }

    void unionIslands(int x, int y) {
        int rootX = findIslandRoot(x);
        int rootY = findIslandRoot(y);
        if (rootX != rootY) {
            islandRoot[rootY] = rootX;
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        numRows = grid2.size();
        numCols = grid2[0].size();
        int totalCells = numRows * numCols;
        islandRoot.resize(totalCells);
        islandStatus.resize(totalCells, 0);

        // Initialize islandRoot array and perform union for grid2
        iota(islandRoot.begin(), islandRoot.end(), 0);

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1) {
                    int currentIndex = row * numCols + col;
                    if (col + 1 < numCols && grid2[row][col + 1] == 1) {
                        unionIslands(currentIndex, currentIndex + 1);
                    }
                    if (row + 1 < numRows && grid2[row + 1][col] == 1) {
                        unionIslands(currentIndex, currentIndex + numCols);
                    }
                }
            }
        }

        // Mark invalid sub-islands
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1 && grid1[row][col] == 0) {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    islandStatus[rootIndex] = 2; // Mark as invalid sub-island
                }
            }
        }

        // Count valid sub-islands
        int subIslandCount = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid2[row][col] == 1) {
                    int rootIndex = findIslandRoot(row * numCols + col);
                    if (islandStatus[rootIndex] == 0) {
                        subIslandCount++;
                        islandStatus[rootIndex] = 1; // Mark as counted
                    }
                }
            }
        }

        return subIslandCount;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();