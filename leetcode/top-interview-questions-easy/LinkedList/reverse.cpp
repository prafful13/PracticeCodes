/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define Node ListNode

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        Node *curr = head, *head2 = NULL;
        while(curr!=NULL)   {
            Node *temp = curr->next;
            curr->next = head2;
            head2 = curr;
            curr = temp;
        }
        head = head2;
        return head2;
    }
};
