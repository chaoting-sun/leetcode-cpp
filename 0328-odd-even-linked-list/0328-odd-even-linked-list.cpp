/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *oddCurr = oddHead, *evenCurr = evenHead;
        bool isOdd = true;
        while (true) {
            if (isOdd) {
                if (!evenCurr->next) break;
                oddCurr->next = evenCurr->next;
                oddCurr = oddCurr->next;
            } else {
                if (!oddCurr->next) break;
                evenCurr->next = oddCurr->next;
                evenCurr = evenCurr->next;
            }
            isOdd = !isOdd;
        }
        evenCurr->next = nullptr;
        oddCurr->next = evenHead;
        return oddHead;
    }
};