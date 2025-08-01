
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL) return false;
        if(q==NULL) return false;

        if(p->val != q->val) return false;
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        return l && r;
    }
};