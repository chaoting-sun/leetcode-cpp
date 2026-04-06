# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head, n):
        prev = None
        curr = head
        for _ in range(n):
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)

        prev_left = dummy
        for _ in range(left - 1):
            prev_left = prev_left.next
        
        n_sublist = right - left + 1

        sublist_head = prev_left.next
        after_right = sublist_head
        for _ in range(n_sublist):
            after_right = after_right.next

        sublist_new_head = self.reverse(sublist_head, n_sublist)
        
        prev_left.next = sublist_new_head
        sublist_head.next = after_right

        return dummy.next