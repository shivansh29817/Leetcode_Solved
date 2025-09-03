class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        # Edge case: if list is empty or has one node
        if not head or not head.next or k == 0:
            return head
        
        # Calculate the length of the list and find the last node
        length = 1
        last_node = head
        while last_node.next:
            last_node = last_node.next
            length += 1
        
        # Normalize k to avoid extra rotations
        k = k % length
        if k == 0:
            return head

        # Find the node just before the point of rotation
        split_point = length - k
        new_tail = head
        
        for _ in range(split_point - 1):
            new_tail = new_tail.next
        
        # New head is the next node of the new tail
        new_head = new_tail.next
        
        # break the link and rotate
        new_tail.next = None
        last_node.next = head

        return new_head