/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */
var connect = function(root) {
    if(!root) return root;
    let que = [];
    que.push(root);
    while(que.length) {
        let temp = [];
        while(que.length) {
            let node = que.shift();
            if(node.left) {
                if(temp.length) {
                    temp[temp.length - 1].next = node.left;
                }
                temp.push(node.left);
            }
            if(node.right) {
                if(temp.length) {
                    temp[temp.length - 1].next = node.right;
                }
                temp.push(node.right);
            }
        }
        que = temp
    }
    return root
};