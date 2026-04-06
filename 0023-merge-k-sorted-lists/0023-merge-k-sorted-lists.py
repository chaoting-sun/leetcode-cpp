# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # need i as tie-breaker
        hq = [(head.val, i, head) for i, head in enumerate(lists) if head]
        heapq.heapify(hq)

        dummy = ListNode()
        curr = dummy

        while hq:
            _, i, head = heapq.heappop(hq)
            curr.next = head
            curr = curr.next
            
            if head.next:
                heapq.heappush(hq, (head.next.val, i, head.next))

        return dummy.next