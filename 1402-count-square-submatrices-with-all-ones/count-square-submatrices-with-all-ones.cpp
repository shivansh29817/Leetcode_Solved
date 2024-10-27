class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>0 && j>0 && mat[i][j]){
                    mat[i][j] = max(mat[i][j], 1+min({mat[i-1][j],mat[i][j-1],mat[i-1][j-1]}));
                }
                cnt += mat[i][j];
            }
        }
        return cnt;
    }
};
auto speedup = [](){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();