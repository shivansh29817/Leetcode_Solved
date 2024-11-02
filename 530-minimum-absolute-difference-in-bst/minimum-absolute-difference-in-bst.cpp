class Solution {
    void dfs(TreeNode* root, int &ans, int &pre) {
        if(!root) return;
        
        dfs(root -> left, ans, pre);
        ans =min(ans, root -> val - pre);
        pre = root -> val;
        dfs(root -> right, ans, pre); 
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e9, pre = -1e9;
        dfs(root, ans, pre);
        return ans;
    }
}; 