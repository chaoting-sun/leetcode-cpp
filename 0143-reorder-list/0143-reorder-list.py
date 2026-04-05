# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return

        # separate the left and right sides
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        right_head = slow.next
        slow.next = None

        # reverse the right linked list
        prev = None
        curr = right_head
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        right_head = prev

        # merge
        left_curr = head
        right_curr = right_head
        while right_curr:
            left_next = left_curr.next
            right_next = right_curr.next
            left_curr.next = right_curr
            right_curr.next = left_next

            left_curr = left_next
            right_curr = right_next


# separate
# 1 2 3
# 4 5

# inverse
# 5 4

# merge
# 1 2 3
# 5 4

# 1 5 2 4 3