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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;

        while (tmp1 != NULL || tmp2!= NULL || carry != 0) {
            int sum = carry;
            if (tmp1 != NULL) {
                sum+=tmp1->val;
                tmp1 = tmp1->next;
            }

            if (tmp2 != NULL) {
                sum+=tmp2->val;
                tmp2 = tmp2->next;
            }
            
            int num = sum % 10;
            carry = sum/10;
            ListNode* newNode = new ListNode(num);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;
    }
};
