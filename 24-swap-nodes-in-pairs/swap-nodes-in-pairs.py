# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head==None or head.next==None):
            return head
        
        dummy=ListNode()
        prev=dummy
        

        while(head!=None and head.next!=None):
            first=head
            second=head.next
            
            prev.next=second
            first.next=second.next
            second.next=first

            head=first.next
            prev=first

        return dummy.next