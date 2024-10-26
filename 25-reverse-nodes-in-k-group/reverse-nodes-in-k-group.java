/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    int i = 0;
    int x = 0;
    int n = 0;
    ListNode st = null;
    ListNode prvst = null;
    ListNode z = null;

    public ListNode reverseKGroup(ListNode head, int k) {
        if (k == 1 || k == 0) {
            return head;
        }
        ListNode temp = head;
        while (temp != null) {
            temp = temp.next;
            n++;
        }
        x = k;
        int p = n / k;
        i = n - x * p;
        ListNode y = new ListNode();
        y.next = head;

        ListNode t = solve(y, head, k);
        ListNode a = t;
        if(n%k==0 && n!=k){
            while(a.next!=null){
                a= a.next;
            }
            a.next = z;
        }
        return t;
    }

    public ListNode solve(ListNode prv, ListNode head, int k) {
        if (head == null) {
            z = prv;
            return head;
        }
        ListNode last = solve(prv.next, head.next, k); // [1,2,3,4,5,6]
        if (i > 0) {
            i--;
            st = head;
            prvst = prv;
            return head;
        } else if (x != 1) {
            head.next = prv;
            x--;
            return head;
        } else if (x == 1) {
            head.next = st;
            st = prvst;
            x = k;
            if (k == n) {
                return z;
            }else if(n%k==0){
                prv.next = z;
            }
            prvst = prv;
            return st;
        }
        return prvst;
    }
}