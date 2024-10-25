class Solution {
public:
  int n;
  int m;
    void dfs(vector<vector<char>>& grid, int i, int j) {
      if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || grid[i][j] == '2')
            return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < m) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
                j++;
            }
            i++;
        }
     return cnt;
    }
};