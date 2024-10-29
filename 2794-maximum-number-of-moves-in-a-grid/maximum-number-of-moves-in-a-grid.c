const int move[3][2] = {{-1,1}, {0,1}, {1,1}};

void dfs(int** grid, const int m, const int n, int x, int y, int cnt, int* ret) {
    for (int i = 0; i < 3; ++i) {
        int nx = x + move[i][0], ny = y + move[i][1];
        
        if (nx < 0 || nx == m || ny == n)
            continue;
        
        if (grid[x][y] < grid[nx][ny]) {
            dfs(grid, m, n, nx, ny, cnt + 1, ret);
            grid[nx][ny] = 0;
        }
    }
    
    *ret = *ret < cnt ? cnt : *ret;
}

int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;
        
    for (int i = 0; i < gridSize; ++i) {
        dfs(grid, gridSize, *gridColSize, i, 0, 0, &ret);
    }
        
    return ret;
}