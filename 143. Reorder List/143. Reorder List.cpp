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
    //middle of the linked list
    ListNode* middleLL(ListNode* head) {
        ListNode* fast = head; 
        ListNode* slow = head;

        while (fast!= NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    void reorderList(ListNode* head) {
        if (head == NULL ||  head->next == NULL) {
            return;
        }

        ListNode* middleNode = middleLL(head);

        //Reversing the second half
        ListNode* prev = NULL;
        ListNode* curr = middleNode;
        while (curr != NULL) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while (second->next != NULL) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
