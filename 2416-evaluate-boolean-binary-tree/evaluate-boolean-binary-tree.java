class Solution {
    public boolean evaluateTree(TreeNode root) {
        
        if(root.left == null && root.right == null) {
            return root.val != 0;
        }

        boolean evalLeft = evaluateTree(root.left);
        boolean evalRight = evaluateTree(root.right);

        boolean evalRoot;
        if(root.val == 2) {
            evalRoot = evalLeft | evalRight;
        }
        else {
            evalRoot = evalLeft & evalRight;
        }

        return evalRoot;
    }
}