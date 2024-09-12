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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

         // Step 2: Initialize a dummy node to help with list creation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Step 3: While the heap is not empty, extract the smallest node
        while (!minHeap.empty()) {
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            
            // Add the smallest node to the merged list
            current->next = smallestNode;
            current = current->next;

            // If the smallest node has a next node, push it into the heap
            if (smallestNode->next != nullptr) {
                minHeap.push(smallestNode->next);
            }
        }

        // Return the merged list (dummy->next is the start of the merged list)
        return dummy->next;
        
    }
};
