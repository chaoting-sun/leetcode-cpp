# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
#         # need i as tie-breaker
#         hq = [(head.val, i, head) for i, head in enumerate(lists) if head]
#         heapq.heapify(hq)

#         dummy = ListNode()
#         curr = dummy

#         while hq:
#             _, i, head = heapq.heappop(hq)
#             curr.next = head
#             curr = curr.next
            
#             if head.next:
#                 heapq.heappush(hq, (head.next.val, i, head.next))

#         return dummy.next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        elif len(lists) == 1:
            return lists[0]

        mid = len(lists) // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])
        return self.merge(left, right)

    def merge(self, left, right):
        dummy = ListNode()
        curr = dummy
        while left and right:
            if left.val <= right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next
            curr = curr.next

        curr.next = left if left else right
        return dummy.next