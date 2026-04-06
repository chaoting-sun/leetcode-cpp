# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, head_node, prev_node, stop_node):
        prev = prev_node
        curr = head_node
        while curr != stop_node:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # add dummy node at the start
        dummy = ListNode()
        dummy.next = head

        # find the left and right boundary (outside)
        left_node = right_node = dummy
        for _ in range(left - 1):
            left_node = left_node.next
        for _ in range(right + 1):
            right_node = right_node.next

        # reverse the linked list between left and right
        first_node = self.reverse(left_node.next, right_node, right_node)
        
        # reconnect the linked list
        left_node.next = first_node

        return dummy.next

# head = 1
# l=1, r=1

# d 1
# l
#     r
# last_node = 1


# l=2, r=4
# 1 2 3 4 5
