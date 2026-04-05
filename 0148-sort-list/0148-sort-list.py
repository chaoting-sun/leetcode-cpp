# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         if not head:
#             return None
        
#         nodes = []
#         curr = head
#         while curr:
#             nodes.append(curr)
#             curr = curr.next
        
#         nodes.sort(key=lambda x: x.val)

#         for i in range(len(nodes) - 1):
#             nodes[i].next = nodes[i + 1]
#         nodes[-1].next = None

#         return nodes[0]

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        right_head = slow.next
        slow.next = None

        left_head = self.sortList(head)
        right_head = self.sortList(right_head)

        return self.merge(left_head, right_head)


    def merge(self, left_head, right_head):
        dummy = ListNode()
        curr = dummy
        left_curr = left_head
        right_curr = right_head

        while left_curr and right_curr:
            if left_curr.val <= right_curr.val:
                curr.next = left_curr
                left_curr = left_curr.next
            else:
                curr.next = right_curr
                right_curr = right_curr.next

            curr = curr.next

        curr.next = left_curr if left_curr else right_curr 
        return dummy.next

'''
test case: 3 2 1
trace:
3 2 1
  s
    f
right_head = 1


test case: 2 1
trace:
2 1
right_head = 1
left_head = sortList(2) -> 2
right_head = sortList(1) -> 1

dummy -> 1 -> 2
            curr

test case: 1
trace:
returns 1

test case:
head = None
trace:
returns None
'''