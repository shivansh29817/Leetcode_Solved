class Solution {
public:
    vector<vector<int>> v;
    int count = 0;
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return (lh > rh) ? lh+1 : rh+1;
    }

    void printLevel(TreeNode *root, int level) {
        if(!root) { return; }
        if(level == 1) v[count].push_back(root->val);
        else if(level > 1) {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

    void levelorderTraversal(TreeNode *root) {
        if(root == NULL) return;
        int h = height(root);
        for(int i=1; i<=h; i++) {
            v.push_back({});
            printLevel(root, i);
            count++;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        levelorderTraversal(root);
        vector<int> res;
        for(int i=0; i<v.size(); i++) {
            int temp = v[i].size();
            res.push_back(v[i][temp - 1]);
        }
        
        return res;
    }
};