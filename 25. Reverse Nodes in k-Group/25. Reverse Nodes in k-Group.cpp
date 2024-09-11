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
    //Code for reversing the LL
    ListNode* reverseLL(ListNode* tmp) {
        ListNode* curr = tmp;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    //To find kth node
    ListNode* getKthNode(ListNode* tmp, int k) {
        while (tmp != NULL && --k>0) {
            tmp = tmp->next;
        }

        return tmp;
    }   

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* prev = NULL;

        while (tmp != NULL) {
            ListNode* kThNode = getKthNode(tmp, k);
            if (kThNode == NULL) {
                if (prev) prev->next = tmp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLL(tmp);

            if (tmp == head) {
                head = kThNode;
            } else {
                prev->next = kThNode;
            }

            prev = tmp;
            tmp = nextNode;
        } 

        return head;
    }
};
