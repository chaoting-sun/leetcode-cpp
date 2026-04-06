# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
#         # count nodes
#         total = 0
#         curr = head
#         while curr:
#             total += 1
#             curr = curr.next
        
#         k = total - n

#         # remove Nth nodes
#         dummy = ListNode(next=head)
#         curr = dummy
#         for _ in range(k):
#             curr = curr.next
        
#         curr.next = curr.next.next

#         return dummy.next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        slow = fast = dummy
        for _ in range(n):
            fast = fast.next
        
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        slow.next = slow.next.next
        return dummy.next
          