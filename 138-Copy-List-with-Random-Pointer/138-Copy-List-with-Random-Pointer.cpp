/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertInBetween(Node* head) {
        Node* tmp = head;

        //(Step 1) To create and insert copy nodes in between
        while (tmp != NULL) {
            Node* copy = new Node(tmp->val);
            copy->next = tmp->next;
            tmp->next = copy;

            tmp = tmp->next->next;
        }
    }

    void connectRandom(Node* head) {
        //(Step 2) To point random pointer
        Node* tmp = head;
        while (tmp != NULL) {
            Node* copy = tmp->next;

            if (tmp->random == NULL) {
                copy->random = NULL;
            } else {
                copy->random = tmp->random->next;
            }
            tmp = tmp->next->next;
        }
    }

    Node* connectDeepCopy(Node* head) {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        Node* tmp = head;
        while (tmp != NULL) {
            res->next = tmp->next;
            res = res->next;
            tmp->next = tmp->next->next;
            tmp = tmp->next;
            
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL) { // Edge case
            return NULL;
        }

        insertInBetween(head);
        connectRandom(head);
        return connectDeepCopy(head);
    }
};
