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
    ListNode* findNthNode(ListNode* head, int k) {
        ListNode* tmp = head;
        int cnt = 1;
        while (tmp != NULL) {
            if (cnt == k) return tmp;
            cnt++;
            tmp = tmp->next;
        }

        return tmp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || k == 0 || head->next == NULL) {
            return head;
        }
        int len=1; 
        ListNode*  tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len += 1;
        }
        tail->next = head;

        //This edge case is not handled by the the editor
        // if (k % len == 0) return head; 

        k = k% len;
        
        ListNode* newTailNode = findNthNode(head, len-k);
        head = newTailNode->next;
        newTailNode->next = NULL;

        return head;
    }
};
